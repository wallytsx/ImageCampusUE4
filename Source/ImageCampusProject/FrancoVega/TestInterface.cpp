// Fill out your copyright notice in the Description page of Project Settings.

#include "TestInterface.h"
#include "HealthComponentFrank.h"
#include "GameFramework/Actor.h"


// Add default functionality here for any IDamageable functions that are not pure virtual.

void IDamageableFrank::OnTakeDamage(float Damage)
{
	UHealthComponentFrank* HealthComponent = GetHealthComponent();
	if (HealthComponent == nullptr)
		return;

	AActor* HealthComponentOwner = HealthComponent->GetOwner();

	FDamageEvent DamageEvent;

	Damage = HealthComponentOwner->TakeDamage(Damage, DamageEvent, nullptr, nullptr);

	HealthComponent->TakeDamage(Damage);
}