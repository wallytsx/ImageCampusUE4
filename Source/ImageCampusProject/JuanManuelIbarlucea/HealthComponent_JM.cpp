// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent_JM.h"

// Sets default values for this component's properties
UHealthComponent_JM::UHealthComponent_JM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent_JM::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


void UHealthComponent_JM::ApplyDamage(int _damage)
{
	Health -= _damage;
}

// Called every frame
void UHealthComponent_JM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

