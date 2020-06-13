// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWeapon.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "TimerManager.h"
#include "ImageCampusProject/ImageCampusProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "ImageCampusProject/AssetLoaderManager.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComp"));

	PickupCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupCollision"));
	PickupCollision->SetupAttachment(RootComp);

	MeshTP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshTP"));
	MeshTP->SetupAttachment(RootComp);
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	PickupCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnPickupCollisionOverlapped);

	CurrentAmmo = DefaultAmmo;
	AAssetLoaderManager* AssetLoader = Cast<AAssetLoaderManager>(AAssetLoaderManager::StaticClass()->GetDefaultObject());
	AssetLoader->AddAssetToLoad(MeshTP2);
	AssetLoader->OnAssetsLoadedDelegate.AddUObject(this, &ABaseWeapon::OnAssetLoadComplete);
}

void ABaseWeapon::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseWeapon::OnPickupCollisionOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto* Character = Cast<AImageCampusProjectCharacter>(Other);
	if (!IsValid(Character))
		return;

	Character->OnPickupTriggered(this);

	bIsOnTheFloor = false;
	PickupCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	OnPickedUp(Character);

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, ABaseWeapon::StaticClass(), Actors);
}

void ABaseWeapon::OnAssetLoadComplete()
{
	MeshTP->SetSkeletalMesh(MeshTP2.Get());
}

void ABaseWeapon::Fire()
{
	UE_LOG(LogTemp, Log, TEXT("Fire!"));

	// Can Fire... !IsOnTheFloor.. etc
	if (CurrentAmmo > 0)
	{
		FTransform MuzzleFlashTransform = MeshTP->GetSocketTransform(MuzzleFlashSocketName);

		// Spawn bullet
		CurrentAmmo--;
	}
}

void ABaseWeapon::Reload()
{
	UE_LOG(LogTemp, Log, TEXT("Reload!"));
	CurrentAmmo = DefaultAmmo;
}

void ABaseWeapon::Drop()
{
	bIsOnTheFloor = true;
	RootComponent->DetachFromParent();
	PickupCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// find floor location
}
