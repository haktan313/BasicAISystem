

#include "BasicAISystemThings/Decorator/BTDecorator_HasPatrolRoute.h"
#include "AIController.h"
#include "BasicAISystemThings/Interface_AISystem.h"
#include "BasicAISystemThings/PatrolPoint.h"

UBTDecorator_HasPatrolRoute::UBTDecorator_HasPatrolRoute()
{
	NodeName = TEXT("Has Patrol Route");
}

bool UBTDecorator_HasPatrolRoute::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if(AIController)
	{
		APawn* controlledPawn = AIController->GetPawn();
		if(controlledPawn)
		{
			APatrolPoint* patrolSpline = IInterface_AISystem::Execute_GetPatrolSpline(controlledPawn);
			if(patrolSpline)
			{
				return true;
			}
		}
	}
	return false;
}
