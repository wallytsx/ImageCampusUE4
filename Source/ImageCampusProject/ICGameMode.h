// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ICGameMode.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API AICGameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> MyDefaultPawnClass;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

};
