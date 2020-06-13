// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class USkeletalMesh;

UCLASS()
class IMAGECAMPUSPROJECT_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ABaseWeapon();


	virtual void Fire();
	virtual void Reload();
	virtual void Drop();

	bool IsInPickupMode() const { return bIsOnTheFloor; }
	USkeletalMeshComponent* GetMeshTP() const { return MeshTP; }

protected:

	UPROPERTY()
	class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UBoxComponent* PickupCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* MeshTP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<USkeletalMesh> MeshTP2;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile | Muzzle Flash ")
	FName MuzzleFlashSocketName;

	UPROPERTY(EditAnywhere)
	float ReloadTime;

	UPROPERTY(EditAnywhere)
	int DefaultAmmo;

	bool bIsOnTheFloor = true;
	int CurrentAmmo = 0;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	virtual void OnPickupCollisionOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPickedUp(class AImageCampusProjectCharacter* Character);

	UFUNCTION()
	void OnAssetLoadComplete();

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
