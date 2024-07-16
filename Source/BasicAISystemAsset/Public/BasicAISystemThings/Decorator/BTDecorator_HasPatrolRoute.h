

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_HasPatrolRoute.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTDecorator_HasPatrolRoute : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_HasPatrolRoute();
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

};
