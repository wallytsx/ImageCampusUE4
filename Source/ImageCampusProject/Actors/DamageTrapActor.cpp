// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageTrapActor.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "ImageCampusProject/ICDamageable.h"

// Sets default values
ADamageTrapActor::ADamageTrapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComp"));

	DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageVolume"));
	DamageVolume->SetupAttachment(RootComp);
}

// Called when the game starts or when spawned
void ADamageTrapActor::BeginPlay()
{
	Super::BeginPlay();
	
	DamageVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	DamageVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapeedEnd);


	GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::DamegeVolumeTick, DamageInterval, true);
}

void ADamageTrapActor::EndPlay(EEndPlayReason::Type EndPlayReason)
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
void ADamageTrapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//OnDamageEvent.Broadcast();
}

void ADamageTrapActor::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	ActorsToDamage.AddUnique(Other);

	OnActorOverlapped(Other);
	OnActorOverlappedNative(Other);
}

void ADamageTrapActor::OnActorOverlappedNative_Implementation(AActor* Actor)
{
	UE_LOG(LogTemp, Warning, TEXT(" OnActorOverlappedNative_Implementation - Other Actor Name: %s"), *Actor->GetName());
}

void ADamageTrapActor::OnDamageVolumeOverlapeedEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr)
		return;

	ActorsToDamage.Remove(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *OtherActor->GetName());
}

void ADamageTrapActor::DamegeVolumeTick()
{
	UE_LOG(LogTemp, Warning, TEXT("DamegeVolumeTick"));

	for (AActor* Actor : ActorsToDamage)
	{
		IICDamageable* Damageable = Cast<IICDamageable>(Actor);

		//Damageable->OnTakeDamage(DamageToCause, this);
	}
}