

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_AttackConditionCheck.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UBTService_AttackConditionCheck : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AttackConditionCheck();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	UPROPERTY(EditAnywhere,Category="Blackboard")
	FBlackboardKeySelector TargetActorKey;
	UPROPERTY(EditAnywhere,Category="Blacboard")
	int amountOfTokenNedded = 1;
	UPROPERTY(EditAnywhere,Category="Blacboard", meta = (ClampMin = "0"))
	int minTimer = 2;
	
	AActor* targetActor;
	AActor* ownersActor;
	int conditionTimer;
	
};
