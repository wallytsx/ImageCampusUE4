

#pragma once
#include "Engine.h"
#include "ActorProjectile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorWeapon.generated.h"

UCLASS()
class BASICSYSTEMWEAPONS_API AActorWeapon : public AActor
{
	GENERATED_BODY()

private:
	int iteratorBullet;
public:	
	// Sets default values for this actor's properties
	AActorWeapon();
	enum TypeFire{Auto,Semi,Bust,Shotgun,};
	TypeFire typeFire;
	int GetTypeFire();
	void Fire();
	float delayIteratorShoot;
	float auxDelayIteratorShoot;
	bool bInFire;
	UPROPERTY(EditAnywhere)
	class AActorProjectile* bullet;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void InstanciateBullet();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
