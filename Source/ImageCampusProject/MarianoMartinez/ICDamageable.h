#pragma once

#include "CoreMinimal.h"
#include "ICDamageable.generated.h"

/* must have BlueprintType as a specifier to have this interface exposed to blueprints
   with this line you can easily add this interface to any blueprint class */
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
};