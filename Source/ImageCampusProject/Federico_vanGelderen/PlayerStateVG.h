// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateVG.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API APlayerStateVG : public APlayerState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int PlayerLives;
	
	int CurrentPlayerLives;

protected:
	virtual void BeginPlay() override;
	int GetPlayerLives() const;
public:
	void RemovePlayerLive();
	bool HasLives() { return CurrentPlayerLives > 0; }
};
