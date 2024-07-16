


#include "BasicAISystemThings/Tasks/BTTask_FindNextPatrolPoint.h"
#include "AIController.h"
#include "BasicAISystemThings/Interface_AISystem.h"
#include "BasicAISystemThings/PatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindNextPatrolPoint::UBTTask_FindNextPatrolPoint()
{
	NodeName = TEXT("FindNextPatrolPoint");
}

EBTNodeResult::Type UBTTask_FindNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if(AIController)
	{
		APawn* pawn = AIController->GetPawn();
		if(pawn)
		{
			APatrolPoint* patrolSpline = IInterface_AISystem::Execute_GetPatrolSpline(pawn);
			if(patrolSpline)
			{
				FVector patrolPointLocation = patrolSpline->GetPatrolRouteLocation();
				UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
				if(BlackboardComponent)
				{
					BlackboardComponent->SetValueAsVector(point.SelectedKeyName, patrolPointLocation);
					patrolSpline->PatrolRouteIndex();
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}
	return EBTNodeResult::Failed;
}
