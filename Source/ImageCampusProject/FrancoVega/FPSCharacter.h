// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerGun.h"
#include "TestInterface.h"
#include "FPSCharacter.generated.h"

class UHealthComponentFrank;

UCLASS()
class IMAGECAMPUSPROJECT_API AFPSCharacter : public ACharacter , public IDamageableFrank
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
		float SprintMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
		float WalkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
		float OriginalWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
	UPlayerGun* PlayerGun;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(EditAnywhere, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	UPROPERTY(EditAnywhere)
		UHealthComponentFrank* HealthComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveRight(float Value);

	void MoveForward(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void FireGun();

	void StopFireGun();

	void Sprint();

	void StopSprint();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	virtual UHealthComponentFrank* GetHealthComponent() const override { return HealthComponent; }
};
