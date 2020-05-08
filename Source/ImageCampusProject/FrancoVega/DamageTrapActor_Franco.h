// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/BoxComponent.h"
//#include "FPSCharacter.h"
#include "DamageTrapActor_Franco.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnDamageEvent, AActor*);

UCLASS()
class IMAGECAMPUSPROJECT_API ADamageTrapActor_Franco : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageTrapActor_Franco();

	UPROPERTY(EditAnywhere)
	float DamageInterval = 1.5f;

	FOnDamageEvent OnDamageEvent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageVolume;

	UPROPERTY(EditAnywhere)
		float DamageValue;

	FTimerHandle DamageTimerHandle;

	//AActor* TouchedPlayer;

	UPROPERTY()
	TArray<AActor*> ActorsToDamage;

	UFUNCTION()
		void DamageTick();

	UFUNCTION()
		virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnDamageVolumeOverlappedEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
