

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsInIdealRange.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTDecorator_IsInIdealRange : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_IsInIdealRange();
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
public:
	UPROPERTY(EditAnywhere, Category = "AI")
	float eror;
	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector targetActorKey;
	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector idealRangeKey;
};
