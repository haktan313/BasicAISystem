

#include "BasicAISystemThings/UEQSContext_TargetActor.h"

#include "BasicAISystemThings/BasicEnemyAIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

void UUEQSContext_TargetActor::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	UObject* querierObject = QueryInstance.Owner.Get();
	if(!querierObject)
	{
		return;
	}
	AActor* querierActor = Cast<AActor>(querierObject);
	if(!querierActor)
	{
		return;
	}
	AAIController* aiController = UAIBlueprintHelperLibrary::GetAIController(querierActor);
	if(!aiController)
	{
		return;
	}
	ABasicEnemyAIController* enemyAIController = Cast<ABasicEnemyAIController>(aiController);
	if(!enemyAIController)
	{
		return;
	}
	AActor* targetActor = enemyAIController->targetActor;
	if(targetActor)
	{
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, targetActor);
	}
}
