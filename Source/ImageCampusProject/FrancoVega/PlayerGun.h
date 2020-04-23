// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FPSTestProjectile.h"
#include "PlayerGun.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IMAGECAMPUSPROJECT_API UPlayerGun : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerGun();

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSTestProjectile> ProjectileClass;

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, Category = Projectile)
		FRotator ProjectileRotation;

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, Category = Projectile)
		FVector ProjectileLocation;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float FireRate;

	/** Sound to play each time we fire */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool CanShoot;

	/** Sound to play each time we fire */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		float FireRateTimer;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleAnywhere, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	/** AnimMontage to play each time we fire */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	/** AnimMontage to play each time we fire */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USkeletalMeshComponent* Mesh1P;

	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;*/

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Set(USceneComponent* Component);
	void OnFire();
	void OnStopFire();
	/** Returns Mesh1P subobject **/
	//FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
		
};
