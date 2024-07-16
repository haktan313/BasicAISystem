

#pragma once

#include "CoreMinimal.h"
#include "BasicAISystemThings/Enum_AISystem.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetMovementSpeed.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTTask_SetMovementSpeed : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_SetMovementSpeed();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	E_MovementState MovementState;
};
