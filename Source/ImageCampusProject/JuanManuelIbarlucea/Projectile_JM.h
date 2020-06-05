#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile_JM.generated.h"

class UStaticMeshComponent;


UCLASS()
class IMAGECAMPUSPROJECT_API AProjectile_JM : public AActor
{
	GENERATED_BODY()

public:
	AProjectile_JM();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;
};

