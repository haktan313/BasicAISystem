

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetFocus.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTTask_SetFocus : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_SetFocus();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FBlackboardKeySelector targetActorKey;
};
