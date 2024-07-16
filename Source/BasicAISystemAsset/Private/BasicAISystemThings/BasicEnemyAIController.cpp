

#include "BasicAISystemThings/BasicEnemyAIController.h"
#include "BasicAISystemThings/EnemyBase.h"
#include "BasicAISystemThings/Structure_AISystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Damage.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"

ABasicEnemyAIController::ABasicEnemyAIController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	SetPerceptionComponent(*AIPerceptionComponent);

	targetActor = nullptr;
	
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1000.0f;
	SightConfig->LoseSightRadius = 1200.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->SetMaxAge(3.0f);

	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	HearingConfig->HearingRange = 1000.0f;
	HearingConfig->SetMaxAge(2.0f);
	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;

	DamageConfig = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("DamageConfig"));
	DamageConfig->SetMaxAge(2.0f);

	AIPerceptionComponent->ConfigureSense(*SightConfig);
	AIPerceptionComponent->ConfigureSense(*HearingConfig);
	AIPerceptionComponent->ConfigureSense(*DamageConfig);

	AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ABasicEnemyAIController::OnPerceptionUpdated);

	CrowdFollowingComponent = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent());
	CrowdFollowingComponent->SetCrowdAnticipateTurns(true); //default false
	CrowdFollowingComponent->SetCrowdObstacleAvoidance(true);
	CrowdFollowingComponent->SetCrowdSeparation(true); //default false
	CrowdFollowingComponent->SetCrowdOptimizeVisibility(true);
	CrowdFollowingComponent->SetCrowdOptimizeTopology(true);
	CrowdFollowingComponent->SetCrowdPathOffset(true);
	CrowdFollowingComponent->SetCrowdSlowdownAtGoal(false); //default true
	CrowdFollowingComponent->SetCrowdSeparationWeight(2.0f);
	CrowdFollowingComponent->SetCrowdCollisionQueryRange(400.0f);
	CrowdFollowingComponent->SetCrowdPathOptimizationRange(2000.0f);
	CrowdFollowingComponent->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);
	CrowdFollowingComponent->SetCrowdAvoidanceRangeMultiplier(1.0f);
	CrowdFollowingComponent->SetCrowdAffectFallingVelocity(false);
	CrowdFollowingComponent->SetCrowdRotateToVelocity(true);

	/*SetCrowdAnticipateTurns: AI karakterlerinin dönüşleri önceden tahmin etmelerini sağlar.
	SetCrowdObstacleAvoidance: AI karakterlerinin engellerden kaçınmasını etkinleştirir.
	SetCrowdSeparation: AI karakterlerinin birbirinden ayrılmasını sağlar.
	SetCrowdOptimizeVisibility: Görünürlük optimizasyonunu etkinleştirir.
	SetCrowdOptimizeTopology: Topoloji optimizasyonunu etkinleştirir.
	SetCrowdPathOffset: Yolları takip ederken ofset kullanımı sağlar.
	SetCrowdSlowdownAtGoal: Hedefe yaklaştıkça yavaşlamalarını sağlar.
	SetCrowdSeparationWeight: Ayrılma davranışının ağırlığını ayarlar.
	SetCrowdCollisionQueryRange: Çarpışma sorgulama aralığını ayarlar.
	SetCrowdPathOptimizationRange: Yol optimizasyon aralığını ayarlar.
	SetCrowdAvoidanceQuality: Kaçınma kalitesini ayarlar.
	SetCrowdAvoidanceRangeMultiplier: Kaçınma aralığı çarpanını ayarlar.
	SetCrowdAffectFallingVelocity: Düşme hızını etkiler.
	SetCrowdRotateToVelocity: Hız yönüne dönmeyi sağlar.
	
	SetAvoidanceGroup: Kaçınılacak grubu ayarlar.
	SetGroupsToAvoid: Kaçınılacak grupları belirler.
	SetGroupsToIgnore: Göz ardı edilecek grupları belirler.*/
}

void ABasicEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	enemyBase = Cast<AEnemyBase>(InPawn);
	if(enemyBase && enemyBase->BehaviorTree)
	{
		BehaviorTreeFromEnemy = enemyBase->BehaviorTree;
		RunBehaviorTree(BehaviorTreeFromEnemy);

		SetStateAsPassive();
		SetStateNone();

		FS_Range range = enemyBase->SetRange_Implementation();
		GetBlackboardComponent()->SetValueAsFloat("AttackRange", range.AttackRange);
		GetBlackboardComponent()->SetValueAsFloat("DefanceRange", range.DefanceRange);
	}
}

void ABasicEnemyAIController::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	for(AActor* sensedActor : UpdatedActors)
	{
		if(sensedActor->ActorHasTag("Player"))
		{
			HandleSense(sensedActor);
			targetActor = sensedActor;
		}
	}
}

void ABasicEnemyAIController::HandleSense(AActor* sensedTargetActor)
{
	if(PlayerSensed(sensedTargetActor, E_SenseType::see))
	{
		targetActor = sensedTargetActor;
		SetStateAsActive();
	}
	else if(PlayerSensed(sensedTargetActor, E_SenseType::hear))
	{
		pointOfInterest = sensedTargetActor->GetActorLocation();
		SetStateAsInvestigate();
	}
	else if(PlayerSensed(sensedTargetActor, E_SenseType::damage))
	{
		pointOfInterest = sensedTargetActor->GetActorLocation();
		SetStateAsInvestigate();
	}
	else
	{
		SetStateAsPassive();
	}
}

bool ABasicEnemyAIController::PlayerSensed(AActor* sensedActor, E_SenseType senseType)
{
	FActorPerceptionBlueprintInfo perceptionInfo;
	AIPerceptionComponent->GetActorsPerception(sensedActor, perceptionInfo);

	for(const auto& stimulus : perceptionInfo.LastSensedStimuli)
	{
		FAISenseID senseID;

		switch (senseType)
		{
		case E_SenseType::see:senseID = UAISense::GetSenseID<UAISenseConfig_Sight>(); break;
		case E_SenseType::hear:senseID = UAISense::GetSenseID<UAISenseConfig_Hearing>(); break;
		case E_SenseType::damage:senseID = UAISense::GetSenseID<UAISenseConfig_Damage>(); break;
		default:return false;
		}
		if(stimulus.Type == senseID)
		{
			pointOfInterest = stimulus.StimulusLocation;
			return true;
		}
	}
	return false;
}



void ABasicEnemyAIController::SetStateAsPassive()
{
	GetBlackboardComponent()->SetValueAsEnum("OnPossessState", (uint8)E_OnPossessState::passive);
}

void ABasicEnemyAIController::SetStateAsInvestigate()
{
	GetBlackboardComponent()->SetValueAsEnum("OnPossessState", (uint8)E_OnPossessState::investigate);
	GetBlackboardComponent()->SetValueAsVector("pointOfInterest", pointOfInterest);
}

void ABasicEnemyAIController::SetStateAsActive()
{
	GetBlackboardComponent()->SetValueAsEnum("OnPossessState", (uint8)E_OnPossessState::active);
	GetBlackboardComponent()->SetValueAsObject("targetActor", targetActor);
}

void ABasicEnemyAIController::SetStateAsDead()
{
	GetBlackboardComponent()->SetValueAsBool("isDead", true);
}


void ABasicEnemyAIController::SetStateNone()
{
	GetBlackboardComponent()->SetValueAsEnum("ActionStates", (uint8)E_ActionStates::none);
}

void ABasicEnemyAIController::SetStateAttack()
{
	GetBlackboardComponent()->SetValueAsEnum("ActionStates", (uint8)E_ActionStates::attacking);
}

void ABasicEnemyAIController::SetStateInactive()
{
	GetBlackboardComponent()->SetValueAsEnum("ActionStates", (uint8)E_ActionStates::inactive);
}
