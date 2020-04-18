#include "Engine/World.h"
#include "ActorProjectile.h"
// Sets default values
AActorProjectile::AActorProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AActorProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AActorProjectile::InstanciateBullet(FTransform tranform)
{
	AActorProjectile* newProjectile = GetWorld()->SpawnActor<AActorProjectile>(GetClass(),tranform);
}

