// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentM.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class IMAGECAMPUSPROJECT_API UHealthComponentM : public UActorComponent
{

	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent_JM();
	UPROPERTY(EditAnywhere)
	int Health;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
