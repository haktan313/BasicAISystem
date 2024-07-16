
#pragma once

#include "CoreMinimal.h"
#include "BasicAISystemThings/Interface_TokenSystem.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "PlayerCharacterAISystem.generated.h"

UCLASS()
class BASICAISYSTEMASSET_API APlayerCharacterAISystem : public ACharacter, public IInterface_TokenSystem
{
	GENERATED_BODY()

	//Components
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Camera,meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Camera,meta=(AllowPrivateAccess="true"))
	class UCameraComponent* FollowCamera;
	//Inputs
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input,meta=(AllowPrivateAccess="true"))
	class UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input,meta=(AllowPrivateAccess="true"))
	class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input,meta=(AllowPrivateAccess="true"))
	class UInputAction* LookAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input,meta=(AllowPrivateAccess="true"))
	class UInputAction* JumpAction;

	class UAnimInstance* animInstance;

public:

	APlayerCharacterAISystem();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private://basic-movement

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

};
