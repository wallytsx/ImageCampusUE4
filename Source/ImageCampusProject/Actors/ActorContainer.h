// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorContainer.generated.h"

UCLASS()
class IMAGECAMPUSPROJECT_API AActorContainer : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AActorContainer();

	void Activate();
	void Deactivate();

protected:

	UPROPERTY(EditAnywhere)
	TArray<AActor*> ManagedActors;

};
