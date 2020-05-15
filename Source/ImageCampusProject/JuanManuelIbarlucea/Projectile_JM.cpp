#include "Components/StaticMeshComponent.h"
#include "Projectile_JM.h"


AProjectile_JM::AProjectile_JM()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}
