// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponentVG.h"

#include "Engine/World.h"
#include "ImageCampusProjectCharacterVG.h"
#include "GameModeBaseVG.h"

UHealthComponentVG::UHealthComponentVG()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UHealthComponentVG::ApplyDamage(float Damage, const AActor* DamageCauser)
{
	Health -= Damage;
	OnDamageRecived.Broadcast(DamageCauser);
}

// Called when the game starts
void UHealthComponentVG::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UHealthComponentVG::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
