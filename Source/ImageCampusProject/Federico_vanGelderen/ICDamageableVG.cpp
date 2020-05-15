
#include "ICDamageableVG.h"
#include "ImageCampusProject/Federico_vanGelderen/HealthComponentVG.h"
#include "GameFramework/Actor.h"

void IICDamageableVG::OnTakeDamage(float Damage, const AActor* DamageCauser)
{
	UHealthComponentVG* HealthComponent = GetHealthComponent();
	if (HealthComponent == nullptr)
		return;

	AActor* HealthComponentOwner = HealthComponent->GetOwner();

	FDamageEvent DamageEvent;

	Damage = HealthComponentOwner->TakeDamage(Damage, DamageEvent,nullptr,nullptr);


	HealthComponent->ApplyDamage(Damage, DamageCauser);
}