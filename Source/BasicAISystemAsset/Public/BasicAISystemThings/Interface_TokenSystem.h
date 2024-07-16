
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_TokenSystem.generated.h"


UINTERFACE(MinimalAPI)
class UInterface_TokenSystem : public UInterface
{
	GENERATED_BODY()
};


class BASICAISYSTEMASSET_API IInterface_TokenSystem
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Token")
	bool TookToken(int amount);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Token")
	void GiveToken(int amount);
};
