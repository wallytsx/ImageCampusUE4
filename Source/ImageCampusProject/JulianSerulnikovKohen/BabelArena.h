// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BabelArena.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API ABabelArena : public AGameMode
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<APawn> DefaultGladiator;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

};
