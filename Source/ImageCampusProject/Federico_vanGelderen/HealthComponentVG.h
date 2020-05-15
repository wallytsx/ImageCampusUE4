// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentVG.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageRecived, const AActor*, DamageCauser);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IMAGECAMPUSPROJECT_API UHealthComponentVG : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponentVG();
	UPROPERTY(EditAnywhere)
	float Health;

	void ApplyDamage(float Damage, const AActor* DamageCauser);

protected:
	UPROPERTY(BlueprintAssignable)
	FOnDamageRecived OnDamageRecived;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
