// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageTrapActorVG.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "ImageCampusProject/Federico_vanGelderen/ICDamageableVG.h"
#include "ImageCampusProject/Federico_vanGelderen/ImageCampusProjectCharacterVG.h"

// Sets default values
ADamageTrapActorVG::ADamageTrapActorVG()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComp"));

	DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageVolume"));
	DamageVolume->SetupAttachment(RootComp);
}

// Called when the game starts or when spawned
void ADamageTrapActorVG::BeginPlay()
{
	Super::BeginPlay();
	
	DamageVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	DamageVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapeedEnd);

	GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::DamegeVolumeTick, DamageInterval, true);
}

void ADamageTrapActorVG::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (DamageVolume->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapped))
	{
		DamageVolume->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	}	

	if (DamageVolume->OnComponentEndOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapeedEnd))
	{
		DamageVolume->OnComponentEndOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapeedEnd);
	}
}

// Called every frame
void ADamageTrapActorVG::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADamageTrapActorVG::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	IICDamageableVG* Damageable = Cast<IICDamageableVG>(Other);
	
	if (Damageable == nullptr)
		return;

	ActorsToDamage.Add(Other);

	UE_LOG(LogTemp, Warning, TEXT(" OnDamageVolumeOverlapped - Other Actor Name: %s"), *Other->GetName());
}

void ADamageTrapActorVG::OnDamageVolumeOverlapeedEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr)
		return;

	ActorsToDamage.Remove(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *OtherActor->GetName());
}

void ADamageTrapActorVG::DamegeVolumeTick()
{
	UE_LOG(LogTemp, Warning, TEXT("DamegeVolumeTick"));

	for (AActor* Actor : ActorsToDamage)
	{
		IICDamageableVG* Damageable = Cast<IICDamageableVG>(Actor);

		Damageable->OnTakeDamage(10.0f, this);

	}
}