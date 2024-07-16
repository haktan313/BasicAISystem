


#include "BasicAISystemThings/EnemyBase.h"
#include "BasicAISystemThings/BasicEnemyAIController.h"
#include "BasicAISystemThings/Enum_AISystem.h"
#include "BasicAISystemThings/Structure_AISystem.h"
#include "GameFramework/CharacterMovementComponent.h"


AEnemyBase::AEnemyBase()
{
	Tags.Add(FName("Enemy"));
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	AnimInstance = GetMesh()->GetAnimInstance();
	AIController = Cast<ABasicEnemyAIController>(GetController());
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



float AEnemyBase::SetMovementSpeed_Implementation(E_MovementState movementState)
{
	float newSpeed;
	switch (movementState)
	{
	case E_MovementState::idle:
		newSpeed = 0.0f;
		break;
	case E_MovementState::walking:
		newSpeed = WalkSpeed;
		break;
	case E_MovementState::running:
		newSpeed = RunSpeed;
		break;
	default:
		newSpeed = 0.0f;
		break;
	}
	GetCharacterMovement()->MaxWalkSpeed = newSpeed;
	return newSpeed;
}

FS_Range AEnemyBase::SetRange_Implementation()
{
	FS_Range range;
	range.AttackRange = AttackRange;
	range.DefanceRange = DefanceRange;
	return range;
}

APatrolPoint* AEnemyBase::GetPatrolSpline_Implementation()
{
	return patrolSpline;
}

