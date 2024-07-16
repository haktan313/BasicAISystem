


#include "PlayerCharacter/PlayerCharacterAISystem.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


APlayerCharacterAISystem::APlayerCharacterAISystem()
{
	Tags.Add("Player");
	PrimaryActorTick.bCanEverTick = true;
	
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	springArm->SetupAttachment(RootComponent);
	springArm->bUsePawnControlRotation = true;
	springArm->TargetArmLength = 400.0f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(springArm);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void APlayerCharacterAISystem::BeginPlay()
{
	Super::BeginPlay();
	animInstance = GetMesh()->GetAnimInstance();
	if(APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* localPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			localPlayerSubsystem->AddMappingContext(InputMappingContext,0);
		}
	}
}

void APlayerCharacterAISystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacterAISystem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	enhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&APlayerCharacterAISystem::Move);
	enhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&APlayerCharacterAISystem::Look);
	enhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Triggered,this,&APlayerCharacterAISystem::Jump);
}



void APlayerCharacterAISystem::Move(const FInputActionValue& Value)
{
	FVector2d input = Value.Get<FVector2d>();

	const FRotator rotation = Controller->GetControlRotation();
	const FRotator yawRotation(0,rotation.Yaw,0);

	const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(forwardDirection,input.Y);
	AddMovementInput(rightDirection,input.X);
}

void APlayerCharacterAISystem::Look(const FInputActionValue& Value)
{
	FVector2d input = Value.Get<FVector2d>();

	AddControllerYawInput(input.X);
	AddControllerPitchInput(input.Y * -1);
}

