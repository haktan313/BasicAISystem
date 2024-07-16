

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_MoveToRadius.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTTask_MoveToRadius : public UBTTask_MoveTo
{
	GENERATED_BODY()

public:
	UBTTask_MoveToRadius();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, Category = Node)
	FBlackboardKeySelector RadiusKey;
};
