

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enum_AISystem.h"
#include "BasicEnemyAIController.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API ABasicEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	ABasicEnemyAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
protected:
	
	virtual void OnPossess(APawn* InPawn) override;
	
	UFUNCTION()
	void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	class UCrowdFollowingComponent* CrowdFollowingComponent;

	class UAIPerceptionComponent* AIPerceptionComponent;

	class UAISenseConfig_Sight* SightConfig;

	class UAISenseConfig_Hearing* HearingConfig;

	class UAISenseConfig_Damage* DamageConfig;

	FVector pointOfInterest;

public:

	AActor* targetActor;

	class AEnemyBase* enemyBase;

	class UBehaviorTree* BehaviorTreeFromEnemy;

	class UBlackboardData* BlackboardDataFromEnemy;

	void HandleSense(AActor* sensedTargetActor);

	bool PlayerSensed(AActor* sensedActor, E_SenseType senseType);

	

	void SetStateAsPassive();

	void SetStateAsInvestigate();

	void SetStateAsActive();

	void SetStateAsDead();

	

	void SetStateNone();

	void SetStateAttack();

	void SetStateInactive();

	int amountOfTokenTaken;
	
};