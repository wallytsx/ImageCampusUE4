// Fill out your copyright notice in the Description page of Project Settings.
#include "ActorWeapon.h"
#include "ActorProjectile.h"

// Sets default values
AActorWeapon::AActorWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Bullet = CreateDefaultSubobject<AActorProjectile>(TEXT("Bullet"));
}

// Called when the game starts or when spawned
void AActorWeapon::BeginPlay()
{
	Super::BeginPlay();
	DelayIteratorShoot = 0;
	AuxDelayIteratorShoot = 0.5f;
	TypeFire = ETypeFire::Semi;
}

// Called every frame
void AActorWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int AActorWeapon::GetTypeFire()
{
	return (int)TypeFire;
}

void AActorWeapon::InstanciateBullet()
{
	FTransform transform = GetActorTransform();
	FVector location = transform.GetLocation();

	transform.SetLocation(location + GetActorForwardVector() * 100.0f);
	Bullet->InstanciateBullet(transform);
}
void AActorWeapon::Fire()
{
	FString DebugginMsj = FString::Printf(TEXT("Disparo"));
	GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
	switch (TypeFire)
	{
	case ETypeFire::Auto:
		//Spawn.
		DebugginMsj = FString::Printf(TEXT("Auto"));
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		if (DelayIteratorShoot > 0)
		{
			DelayIteratorShoot = DelayIteratorShoot - GetWorld()->GetTimeSeconds();
		}
		if (DelayIteratorShoot <= 0)
		{
			DelayIteratorShoot = AuxDelayIteratorShoot;
			//Spawn.
			InstanciateBullet();
		}
		break;
	case ETypeFire::Semi:
		//Spawn.
		DebugginMsj = FString::Printf(TEXT("Semi"));
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		InstanciateBullet();
		break;
	case ETypeFire::Bust:
		DebugginMsj = FString::Printf(TEXT("Bust"));
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		while(IteratorBullet < 3)
		{
			if(DelayIteratorShoot > 0)
			{
				DelayIteratorShoot = DelayIteratorShoot - GetWorld()->GetTimeSeconds();
			}
			if(DelayIteratorShoot <= 0)
			{
				DelayIteratorShoot = AuxDelayIteratorShoot;
				IteratorBullet++;
				//Spawn.
				InstanciateBullet();
			}
		}
		IteratorBullet = 0;
		break;
	case ETypeFire::Shotgun:
			DebugginMsj = FString::Printf(TEXT("Shootgun"));
			GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugginMsj);
		break;
	}
}
