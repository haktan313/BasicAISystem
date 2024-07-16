#pragma once

#include "CoreMinimal.h"
#include "Structure_AISystem.generated.h"

USTRUCT(BlueprintType)

struct FS_Range
{
	GENERATED_BODY()

public:

	FS_Range() : AttackRange(0), DefanceRange(0) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")
	float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")
	float DefanceRange;
};