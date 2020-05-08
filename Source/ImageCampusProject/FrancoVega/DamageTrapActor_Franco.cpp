// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrapActor_Franco.h"
#include "TimerManager.h"
#include "TestInterface.h"
#include "Components/BoxComponent.h"

// Sets default values
ADamageTrapActor_Franco::ADamageTrapActor_Franco()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Volume"));
	DamageVolume->SetupAttachment(RootComp);
	
}

// Called when the game starts or when spawned
void ADamageTrapActor_Franco::BeginPlay()
{
	Super::BeginPlay();
	
	DamageVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	DamageVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);

	//GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::DamageTick, DamageInterval, true);
	
}

// Called when the game starts or when spawned
void ADamageTrapActor_Franco::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (DamageVolume->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapped))
	{
		DamageVolume->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	}

	if (DamageVolume->OnComponentEndOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlappedEnd))
	{
		DamageVolume->OnComponentEndOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);
	}

	
}

// Called every frame
void ADamageTrapActor_Franco::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ADamageTrapActor_Franco::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::DamageTick, DamageInterval, true);

	IDamageableFrank* Damageable = Cast<IDamageableFrank>(Other);

	if (Damageable == nullptr)
		return;

	ActorsToDamage.Add(Other);

	UE_LOG(LogTemp, Warning, TEXT(" OnDamageVolumeOverlapped - Other Actor Name: %s"), *Other->GetName());

	//TouchedPlayer = Other;

	//UE_LOG(LogTemp, Warning, TEXT("Other Actor Name START: %s"), *Other->GetName());

}

void ADamageTrapActor_Franco::OnDamageVolumeOverlappedEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Other == nullptr)
		return;

	//TouchedPlayer = nullptr;

	//UE_LOG(LogTemp, Warning, TEXT("Other Actor Name END: %s"), *Other->GetName());

	ActorsToDamage.Remove(Other);

	if (ActorsToDamage.Num() <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(DamageTimerHandle);
	}

	UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *Other->GetName());

}

void ADamageTrapActor_Franco::DamageTick()
{
	for (AActor* Actor : ActorsToDamage)
	{
		IDamageableFrank* Damageable = Cast<IDamageableFrank>(Actor);

		Damageable->OnTakeDamage(DamageValue);

		UE_LOG(LogTemp, Warning, TEXT("Damage Tick"));
	}
}

