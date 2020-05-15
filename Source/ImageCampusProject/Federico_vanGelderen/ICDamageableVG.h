#pragma once

#include "CoreMinimal.h"
#include "HealthComponentVG.h"
#include "ICDamageableVG.generated.h"

/* must have BlueprintType as a specifier to have this interface exposed to blueprints
   with this line you can easily add this interface to any blueprint class */
UINTERFACE()
class IMAGECAMPUSPROJECT_API UICDamageableVG : public UInterface
{
	GENERATED_BODY()
};

class IMAGECAMPUSPROJECT_API IICDamageableVG
{
	GENERATED_BODY()

public:

	virtual class UHealthComponentVG* GetHealthComponent() const = 0;
	virtual void OnTakeDamage(float Damage, const AActor* DamageCauser);
};