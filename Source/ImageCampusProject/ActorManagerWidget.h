// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActorManagerWidget.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API UActorManagerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(Transient)
	TArray<class AActorContainer*> ActorContainers;

	UPROPERTY(Transient)
	TArray<class UButton*> Buttons;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* VBoxButtons;

	virtual void NativeOnInitialized() override;

	template<int Index>
	void OnButtonClicked();

};
