 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Damageable.h"
#include "TestCharacter.generated.h"



class UHealthComponent;

UCLASS()
class IMAGECAMPUSPROJECT_API ATestCharacter : public ACharacter, public IDamageable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

protected:

	//Variables
	UPROPERTY(VisibleAnywhere)
	UHealthComponent* HealthComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual UHealthComponent* GetHealthComponent() const override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetHit();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
