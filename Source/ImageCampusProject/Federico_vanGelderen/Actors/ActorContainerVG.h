// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorContainerVG.generated.h"

UCLASS()
class IMAGECAMPUSPROJECT_API AActorContainerVG : public AActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	AActorContainerVG();

	void Activate();
	void Deactivate();
	TArray<AActor*> GetManagedActors();

protected:

	UPROPERTY(EditAnywhere)
	TArray<AActor*> ManagedActors;

};
