#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "ImageCampusProject/TestInterface.h"
#include "ActorWeapon.generated.h"

UENUM(BlueprintType)
enum class ETypeFire : uint8
{ 
	Auto, 
	Semi, 
	Bust, 
	Shotgun
};

UCLASS()
class IMAGECAMPUSPROJECT_API AActorWeapon : public AActor
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere)
	class AActorProjectile* Bullet;

	UPROPERTY(EditAnywhere)
	ETypeFire TypeFire;

	float DelayIteratorShoot = 0.0f;
	float AuxDelayIteratorShoot = 0.0f;
	bool bInFire = false;

	// Sets default values for this actor's properties
	AActorWeapon();

	void Fire();

	int GetTypeFire();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InstanciateBullet();

private:

	int IteratorBullet = 0;
};
