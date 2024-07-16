

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "UEQSContext_TargetActor.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UUEQSContext_TargetActor : public UEnvQueryContext
{
	GENERATED_BODY()
protected:
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};
