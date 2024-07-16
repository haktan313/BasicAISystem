#pragma once

#include "CoreMinimal.h"
#include "Enum_AISystem.generated.h"

UENUM(BlueprintType)
enum class E_MovementState : uint8
{
	idle UMETA(DisplayName = "Idle"),
	walking UMETA(DisplayName = "Walking"),
	running UMETA(DisplayName = "Running")
};
UENUM(BlueprintType)
enum class E_SenseType : uint8
{
	see UMETA(DisplayName = "See"),
	hear UMETA(DisplayName = "Hear"),
	damage UMETA(DisplayName = "Damage")
};
UENUM(BlueprintType)
enum class E_OnPossessState : uint8
{
	passive UMETA(DisplayName = "Passive"),
	investigate UMETA(DisplayName = "Investigate"),
	active UMETA(DisplayName = "Active")
};
UENUM(BlueprintType)
enum class E_ActionStates : uint8
{
	none UMETA(DisplayName = "None"),
	attacking UMETA(DisplayName = "Attacking"),
	inactive UMETA(DisplayName = "Inactive")
};