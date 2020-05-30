#include "Projectile_JM.h"
#include "Components/StaticMeshComponent.h"


AProjectile_JM::AProjectile_JM()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}
