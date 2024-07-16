

#pragma once

#include "CoreMinimal.h"
#include "BasicAISystemThings/Enum_AISystem.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_Attack();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	E_AttackType AttackType;
	
};
