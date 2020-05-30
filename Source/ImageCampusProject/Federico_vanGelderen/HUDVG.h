// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ActorSpawnerWidget.h"
#include "HUDVG.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API AHUDVG : public AHUD
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UActorSpawnerWidget> ButtonWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	UActorSpawnerWidget* SpawnerButtonWidget;

	virtual void BeginPlay() override;
};
