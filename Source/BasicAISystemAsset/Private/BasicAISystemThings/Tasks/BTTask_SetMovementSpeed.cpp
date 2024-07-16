


#include "BasicAISystemThings/Tasks/BTTask_SetMovementSpeed.h"

#include "AIController.h"
#include "BasicAISystemThings/Interface_AISystem.h"

UBTTask_SetMovementSpeed::UBTTask_SetMovementSpeed()
{
	NodeName = TEXT("Set Movement Speed");
}

EBTNodeResult::Type UBTTask_SetMovementSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if(AIController)
	{
		APawn* pawn = AIController->GetPawn();
		if(pawn)
		{
			IInterface_AISystem::Execute_SetMovementSpeed(pawn, MovementState);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
