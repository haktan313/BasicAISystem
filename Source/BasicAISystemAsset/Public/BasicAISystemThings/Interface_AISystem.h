

#pragma once

#include "CoreMinimal.h"
#include "PatrolPoint.h"
#include "UObject/Interface.h"
#include "BasicAISystemThings/Structure_AISystem.h"
#include "Interface_AISystem.generated.h"


UINTERFACE(MinimalAPI)
class UInterface_AISystem : public UInterface
{
	GENERATED_BODY()
};


class BASICAISYSTEMASSET_API IInterface_AISystem
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AI")
	float SetMovementSpeed(E_MovementState movementState);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AI")
	FS_Range SetRange();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AI")
	APatrolPoint* GetPatrolSpline();
};
