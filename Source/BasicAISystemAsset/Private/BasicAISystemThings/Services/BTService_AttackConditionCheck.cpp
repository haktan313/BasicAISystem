


#include "BasicAISystemThings/Services/BTService_AttackConditionCheck.h"

#include "BasicAISystemThings/BasicEnemyAIController.h"
#include "BasicAISystemThings/Interface_TokenSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_AttackConditionCheck::UBTService_AttackConditionCheck()
{
	NodeName = TEXT("AttackConditionCheck");
}

void UBTService_AttackConditionCheck::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	ABasicEnemyAIController* AIController = Cast<ABasicEnemyAIController>(OwnerComp.GetAIOwner());
	if(AIController)
	{
		UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
		if(BlackboardComponent)
		{
			targetActor = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetActorKey.SelectedKeyName));
			ownersActor = AIController->GetPawn();
			if(targetActor && ownersActor)
			{
				conditionTimer++;
				if(conditionTimer >= minTimer)
				{
					conditionTimer = 0;
					bool bCanTakeToken = IInterface_TokenSystem::Execute_TookToken(targetActor,amountOfTokenNedded);
					if(bCanTakeToken)
					{
						AIController->amountOfTokenTaken += amountOfTokenNedded;
						AIController->SetStateAttack();
					}
				}
			}
		}
	}
}
