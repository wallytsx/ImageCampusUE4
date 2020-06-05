// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UHealthComponent::ApplyDamage(float Damage, const AActor* DamageCauser)
{
	Health -= Damage;

	UE_LOG(LogTemp, Warning, TEXT("Aplico danio %f"), Health);

	OnDamageReceived.Broadcast(DamageCauser);
	OnNoDynamicDamageReceived.Broadcast(DamageCauser);
}
