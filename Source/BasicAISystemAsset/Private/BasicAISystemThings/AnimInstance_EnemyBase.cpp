

#include "BasicAISystemThings/AnimInstance_EnemyBase.h"

#include "BasicAISystemThings/EnemyBase.h"

void UAnimInstance_EnemyBase::NativeUpdateAnimation(float DeltaSeconds)
{
	if(enemyCharacter)
	{
		FVector velocity = enemyCharacter->GetVelocity();
		speed = velocity.Size();

		FRotator rotation = enemyCharacter->GetControlRotation();
		direction = CalculateDirection(velocity, rotation);
	}
}

void UAnimInstance_EnemyBase::NativeInitializeAnimation()
{
	enemyCharacter = Cast<AEnemyBase>(TryGetPawnOwner());
}
