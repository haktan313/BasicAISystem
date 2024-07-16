

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_SetStateNone.generated.h"


UCLASS()
class BASICAISYSTEMASSET_API UAnimNotify_SetStateNone : public UAnimNotify
{
	GENERATED_BODY()
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	class ABasicEnemyAIController* enemyAIController;
	
};
