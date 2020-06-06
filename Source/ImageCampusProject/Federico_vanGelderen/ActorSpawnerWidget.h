// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActorSpawnerWidget.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API UActorSpawnerWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<AActor> SpawnClass;
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* SpawnerButton;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void SpawnActor();
};
