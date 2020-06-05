// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorContainer.h"

// Sets default values
AActorContainer::AActorContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AActorContainer::Activate()
{
	for (AActor* Actor : ManagedActors)
	{
		Actor->SetActorHiddenInGame(false);
	}
}

void AActorContainer::Deactivate()
{
	for (AActor* Actor : ManagedActors)
	{
		Actor->SetActorHiddenInGame(true);
	}
}