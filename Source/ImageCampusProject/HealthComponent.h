// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnDamageReceivedNoDynamic, const AActor*);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageReceived, const AActor*, dasfadsf);

UCLASS()
class IMAGECAMPUSPROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere)
	float Health;
	
	virtual void ApplyDamage(float Damage, const AActor* DamageCauser);
protected:

	FOnDamageReceivedNoDynamic OnNoDynamicDamageReceived;

	UPROPERTY(BlueprintAssignable)
	FOnDamageReceived OnDamageReceived;

	// Called when the game starts
	virtual void BeginPlay() override;
};
