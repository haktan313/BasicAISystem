
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacterAISystem.generated.h"

UCLASS()
class BASICAISYSTEMASSET_API APlayerCharacterAISystem : public ACharacter
{
	GENERATED_BODY()

public:

	APlayerCharacterAISystem();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
