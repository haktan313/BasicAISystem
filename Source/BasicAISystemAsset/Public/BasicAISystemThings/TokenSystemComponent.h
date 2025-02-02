

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TokenSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASICAISYSTEMASSET_API UTokenSystemComponent : public UActorComponent
{
	GENERATED_BODY()
public:

	bool TookToken(int amount);

	void GiveToken(int amount);

	int currentToken = 0;
};
