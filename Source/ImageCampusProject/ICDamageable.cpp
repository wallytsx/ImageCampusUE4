
#include "ImageCampusProject/ICDamageable.h"
#include "ImageCampusProject/HealthComponent.h"
#include "GameFramework/Actor.h"

void IICDamageable::OnTakeDamage(float Damage, const AActor* DamageCauser) 
{
	UHealthComponent* HealthComponent = GetHealthComponent();
	if (HealthComponent == nullptr)
		return;

	AActor* HealthComponentOwner = HealthComponent->GetOwner();

	FDamageEvent DamageEvent;

	Damage = HealthComponentOwner->TakeDamage(Damage, DamageEvent,nullptr,nullptr);


	HealthComponent->ApplyDamage(Damage, DamageCauser);
}