
#pragma once

#include "CoreMinimal.h"
#include "Interface_AISystem.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class BASICAISYSTEMASSET_API AEnemyBase : public ACharacter, public IInterface_AISystem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	class APatrolPoint* patrolSpline;
	
	class UAnimInstance* AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Range, meta = (AllowPrivateAccess = "true"))
	float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Range, meta = (AllowPrivateAccess = "true"))
	float DefanceRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Speed, meta = (AllowPrivateAccess = "true"))
	float WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Speed, meta = (AllowPrivateAccess = "true"))
	float RunSpeed;

public:

	AEnemyBase();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	class UBehaviorTree* BehaviorTree;

	class ABasicEnemyAIController* AIController;

	virtual float SetMovementSpeed_Implementation(E_MovementState movementState) override;

	virtual FS_Range SetRange_Implementation() override;

	virtual APatrolPoint* GetPatrolSpline_Implementation() override;

	virtual void EnemyAttack_Implementation(E_AttackType attackType) override;

};
