
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class BASICAISYSTEMASSET_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:

	AEnemyBase();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

};
