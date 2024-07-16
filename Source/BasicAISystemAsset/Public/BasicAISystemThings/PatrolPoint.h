

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPoint.generated.h"

UCLASS()
class BASICAISYSTEMASSET_API APatrolPoint : public AActor
{
	GENERATED_BODY()

public:

	APatrolPoint();

	void PatrolRouteIndex();

	FVector GetPatrolRouteLocation();

	int currentPointIndex;
	UPROPERTY(meta=(ClampMin="-1",ClampMax="1"))
	int direction;

	class USplineComponent* SplineComponent;
	
};
