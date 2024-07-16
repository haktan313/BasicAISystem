

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindRandomPatrolPoint.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTTask_FindRandomPatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_FindRandomPatrolPoint();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Radius")
	float Radius = 500.0f;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector point;
};
