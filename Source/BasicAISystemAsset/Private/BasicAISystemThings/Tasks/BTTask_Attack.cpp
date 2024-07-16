


#include "BasicAISystemThings/Tasks/BTTask_Attack.h"

#include "AIController.h"
#include "BasicAISystemThings/BasicEnemyAIController.h"
#include "BasicAISystemThings/EnemyBase.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("Attack");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if(AIController)
	{
		AEnemyBase* enemyBase = Cast<AEnemyBase>(AIController->GetPawn());
		if(enemyBase)
		{
			enemyBase->AIController->SetStateInactive();
			enemyBase->EnemyAttack_Implementation(AttackType);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
