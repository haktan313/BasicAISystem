


#include "Notifys/AnimNotify_SetStateNone.h"
#include "BasicAISystemThings/BasicEnemyAIController.h"
#include "BasicAISystemThings/Interface_TokenSystem.h"

void UAnimNotify_SetStateNone::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if(MeshComp && MeshComp->GetOwner())
	{
		enemyAIController = Cast<ABasicEnemyAIController>(MeshComp->GetOwner()->GetInstigatorController());
		if(enemyAIController)
		{
			enemyAIController->SetStateNone();
			if(enemyAIController->targetActor && enemyAIController->amountOfTokenTaken > 0)
			{
				IInterface_TokenSystem::Execute_GiveToken(enemyAIController->targetActor, enemyAIController->amountOfTokenTaken);
				enemyAIController->amountOfTokenTaken = 0;
			}
		}
	}
}
