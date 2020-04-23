// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGun.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UPlayerGun::UPlayerGun()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	FireRateTimer = FireRate;
}


// Called when the game starts
void UPlayerGun::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerGun::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CanShoot)
	{
		FireRateTimer += DeltaTime;

		if (FireRateTimer >= FireRate)
		{
			// try and fire a projectile
			if (ProjectileClass != NULL)
			{
				UWorld* const World = GetWorld();
				if (World != NULL)
				{
					//Set Spawn Collision Handling Override
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

					// spawn the projectile at the muzzle
					World->SpawnActor<AFPSTestProjectile>(ProjectileClass, FP_MuzzleLocation->GetComponentLocation(), FP_MuzzleLocation->GetComponentRotation(), ActorSpawnParams);
				}
			}

			// try and play the sound if specified
			if (FireSound != NULL)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, ProjectileLocation);
			}

			// try and play a firing animation if specified
			if (FireAnimation != NULL)
			{
				// Get the animation object for the arms mesh
				UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
				if (AnimInstance != NULL)
				{
					AnimInstance->Montage_Play(FireAnimation, 1.f);
				}
			}

			FireRateTimer = 0;
		}
	}

	// ...
}

void UPlayerGun::Set(USceneComponent* Component)
{
	//FirstPersonCameraComponent->SetupAttachment(Component);
}

void UPlayerGun::OnFire()
{
	CanShoot = true;
}

void UPlayerGun::OnStopFire()
{
	CanShoot = false;
	FireRateTimer = FireRate;
}

