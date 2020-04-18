// Fill out your copyright notice in the Description page of Project Settings.
#include "ActorWeapon.h"
#include "BasicSystemWeaponsCharacter.h"

// Sets default values
AActorWeapon::AActorWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bullet = CreateDefaultSubobject<AActorProjectile>(TEXT("Bullet"));
}

// Called when the game starts or when spawned
void AActorWeapon::BeginPlay()
{
	Super::BeginPlay();
	delayIteratorShoot = 0;
	auxDelayIteratorShoot = 0.5f;
	typeFire = Semi;
}

// Called every frame
void AActorWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int AActorWeapon::GetTypeFire()
{
	return (int)typeFire;
}
void AActorWeapon::InstanciateBullet()
{
	FTransform transform = GetActorTransform();
	FVector location = transform.GetLocation();

	transform.SetLocation(location + GetActorForwardVector() * 100.0f);
	bullet->InstanciateBullet(transform);
}
void AActorWeapon::Fire()
{
	FString DebugginMsj = FString::Printf(TEXT("Disparo"));
	GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
	switch (typeFire)
	{
	case Auto:
		//Spawn.
		DebugginMsj = FString::Printf(TEXT("Auto"));
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		if (delayIteratorShoot > 0)
		{
			delayIteratorShoot = delayIteratorShoot - GetGameTimeSinceCreation();
		}
		if (delayIteratorShoot <= 0)
		{
			delayIteratorShoot = auxDelayIteratorShoot;
			//Spawn.
			InstanciateBullet();
		}
		break;
	case Semi:
		//Spawn.
		DebugginMsj = FString::Printf(TEXT("Semi"));
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		InstanciateBullet();
		break;
	case Bust:
		DebugginMsj = FString::Printf(TEXT("Bust"));
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		while(iteratorBullet < 3)
		{
			if(delayIteratorShoot > 0)
			{
				delayIteratorShoot = delayIteratorShoot - GetGameTimeSinceCreation();
			}
			if(delayIteratorShoot <= 0)
			{
				delayIteratorShoot = auxDelayIteratorShoot;
				iteratorBullet++;
				//Spawn.
				InstanciateBullet();
			}
		}
		iteratorBullet = 0;
		break;
		case Shotgun:
			DebugginMsj = FString::Printf(TEXT("Shootgun"));
			GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		break;
	}
}
