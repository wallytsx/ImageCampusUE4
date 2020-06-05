// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBaseVG.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API AGameModeBaseVG : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> MyDefaultPawnClass;

	FTimerHandle RespawnTimerHandle;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	void RespawnPlayer(class APlayerStateVG* PlayerState, APlayerController* PlayerController);
public:
	UPROPERTY(EditAnywhere)
	float RespawnTime;
	
	void OnPlayerDeath(APawn* PlayerPawn);
};
