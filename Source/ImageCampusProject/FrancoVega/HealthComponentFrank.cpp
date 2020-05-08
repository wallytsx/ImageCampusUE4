// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponentFrank.h"

// Sets default values for this component's properties
UHealthComponentFrank::UHealthComponentFrank()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Health = MaxHealth;

	// ...
}


// Called when the game starts
void UHealthComponentFrank::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	// ...
	
}

void UHealthComponentFrank::TakeDamage(float amount)
{
	Health -= amount;

	if (Health <= 0)
	{
		Health = 0;
	}

	UE_LOG(LogTemp, Warning, TEXT("Damage applied, current health is : %i"), Health);
}

