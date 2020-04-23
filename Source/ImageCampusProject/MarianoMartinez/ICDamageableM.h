#pragma once

#include "CoreMinimal.h"
#include "HealthComponentM.h"
#include "ICDamageableM.generated.h"

/* must have BlueprintType as a specifier to have this interface exposed to blueprints
   with this line you can easily add this interface to any blueprint class */
UINTERFACE()
class IMAGECAMPUSPROJECT_API UICDamageableM : public UInterface
{
	GENERATED_BODY()
};

class IMAGECAMPUSPROJECT_API IICDamageableM
{
	GENERATED_BODY()
	
public:

	virtual class UHealthComponentM* GetHealthComponent() const = 0;
};