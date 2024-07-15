// Copyright Epic Games, Inc. All Rights Reserved.

#include "BasicAISystemAssetGameMode.h"
#include "BasicAISystemAssetCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABasicAISystemAssetGameMode::ABasicAISystemAssetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
