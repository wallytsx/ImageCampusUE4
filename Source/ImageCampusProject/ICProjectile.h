// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ICProjectile.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API AICProjectile : public AActor
{
	GENERATED_BODY()

public:

	AICProjectile();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

};
