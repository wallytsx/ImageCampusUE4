// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ButtonVG.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API UButtonVG : public UButton
{
	GENERATED_BODY()
public:
	AActor* MyActor;
	UFUNCTION()
	void OnButtonClicked();
	void SetActor(AActor* Actor);
};
