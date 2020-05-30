 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Damageable.h"
#include "TestCharacter.generated.h"



class UHealthComponent_JM;

UCLASS()
class IMAGECAMPUSPROJECT_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

protected:

	//Variables
	/*UPROPERTY(VisibleAnywhere)
	UHealthComponent_JM* HealthComponent;*/

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//virtual UHealthComponent_JM* GetHealthComponent() const override;
	virtual void Tick(float DeltaTime) override;

	/*UFUNCTION()
	void ApplyDamage(int _damage) const override;*/

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
