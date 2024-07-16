


#include "BasicAISystemThings/Decorator/BTDecorator_IsInIdealRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInIdealRange::UBTDecorator_IsInIdealRange()
{
	NodeName = "Is In Ideal Range";
}

bool UBTDecorator_IsInIdealRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		APawn* pawn = AIController->GetPawn();
		if (pawn)
		{
			UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
			if (BlackboardComp)
			{
				AActor* targetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(targetActorKey.SelectedKeyName));
				if (targetActor)
				{
					float idealRange = BlackboardComp->GetValueAsFloat(idealRangeKey.SelectedKeyName);
					float distance = FVector::Dist(targetActor->GetActorLocation(), pawn->GetActorLocation());
					distance = distance - eror;
					return distance <= idealRange;
				}
			}
		}
	}
	return false;
}
