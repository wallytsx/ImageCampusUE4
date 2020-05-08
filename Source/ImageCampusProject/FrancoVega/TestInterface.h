#pragma once

#include "CoreMinimal.h"
//#include "HealthComponentFrank.h"
#include "TestInterface.generated.h"

//class UHealthComponentFrank;

/* must have BlueprintType as a specifier to have this interface exposed to blueprints
   with this line you can easily add this interface to any blueprint class */
UINTERFACE()
class IMAGECAMPUSPROJECT_API UDamageableFrank : public UInterface
{
	GENERATED_BODY()
};

class IMAGECAMPUSPROJECT_API IDamageableFrank
{
	GENERATED_BODY()

public:

	virtual class UHealthComponentFrank* GetHealthComponent() const = 0;

	virtual void OnTakeDamage(float Damage);

};
