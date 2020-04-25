// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageTrapActor.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FOnDamageEvent, AActor*);

UCLASS()
class IMAGECAMPUSPROJECT_API ADamageTrapActor : public AActor
{
	GENERATED_BODY()
	
public:	

	FOnDamageEvent OnDamageEvent;

	// Sets default values for this actor's properties
	ADamageTrapActor();

protected:

	UPROPERTY()
	class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* DamageVolume;

	UPROPERTY(EditAnywhere)
	float DamageInterval = 3.0f;

	FTimerHandle DamageTimerHandle;

	UPROPERTY()
	TArray<AActor*> ActorsToDamage;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnDamageVolumeOverlapeedEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void DamegeVolumeTick();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
