// Fill out your copyright notice in the Description page of Project Settings.

#include "Damageable.h"
#include "ImageCampusProject/HealthComponent.h"

// Add default functionality here for any IDamageable functions that are not pure virtual.

void IDamageable::OnTakeDamage(float Damage)
{
	UHealthComponent* HealthComponent = GetHealthComponent();
	if (HealthComponent == nullptr)
		return;
	
	AActor* HealthComponentOwner = HealthComponent->GetOwner();
	Damage = HealthComponentOwner->TakeDamage();

	HealthComponent->ApplyDamage(Damage);
}