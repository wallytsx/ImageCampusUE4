#pragma once

#include "CoreMinimal.h"
#include "ICDamageable.generated.h"

UINTERFACE()
class IMAGECAMPUSPROJECT_API UICDamageable : public UInterface
{
	GENERATED_BODY()
};

class IMAGECAMPUSPROJECT_API IICDamageable
{
	GENERATED_BODY()

public:
	
	virtual class UHealthComponent* GetHealthComponent() const = 0;
	virtual void OnTakeDamage(float Damage);

};