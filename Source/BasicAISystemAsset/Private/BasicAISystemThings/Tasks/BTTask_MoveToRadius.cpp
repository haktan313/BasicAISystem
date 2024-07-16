


#include "BasicAISystemThings/Tasks/BTTask_MoveToRadius.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTTask_MoveToRadius::UBTTask_MoveToRadius()
{
	NodeName = TEXT("MoveToRadius");
}

EBTNodeResult::Type UBTTask_MoveToRadius::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp)
	{
		float RadiusValue = BlackboardComp->GetValueAsFloat(RadiusKey.SelectedKeyName);
		AcceptableRadius += RadiusValue;
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
