

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindNextPatrolPoint.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTTask_FindNextPatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_FindNextPatrolPoint();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere,Category="Blackboard")
	FBlackboardKeySelector point;
	
};
