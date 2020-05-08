// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentFrank.generated.h"


UCLASS()
class IMAGECAMPUSPROJECT_API UHealthComponentFrank : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponentFrank();

	UPROPERTY(EditAnywhere, Category = Player)
		int MaxHealth;

	UPROPERTY(EditAnywhere, Category = Player)
		int Health;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	virtual void TakeDamage(float amount);	
};
