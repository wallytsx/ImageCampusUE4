// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActorManagerWidgetVG.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API UActorManagerWidgetVG : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(Transient)
	TArray<class AActor*> ManagedActors;

	UPROPERTY(Transient)
	TArray<class UButton*> Buttons;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UVerticalBox* VBoxButtons;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void OnButtonClicked();

};
