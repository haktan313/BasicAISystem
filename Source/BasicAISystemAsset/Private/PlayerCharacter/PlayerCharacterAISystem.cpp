


#include "PlayerCharacter/PlayerCharacterAISystem.h"


APlayerCharacterAISystem::APlayerCharacterAISystem()
{

	PrimaryActorTick.bCanEverTick = true;

}


void APlayerCharacterAISystem::BeginPlay()
{
	Super::BeginPlay();
	
}


void APlayerCharacterAISystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacterAISystem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

