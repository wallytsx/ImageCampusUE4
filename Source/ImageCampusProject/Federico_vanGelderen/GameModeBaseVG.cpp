// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeBaseVG.h"

#include "PlayerStateVG.h"

void AGameModeBaseVG::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	DefaultPawnClass = MyDefaultPawnClass;
}

void AGameModeBaseVG::OnPlayerDeath(APawn* PlayerPawn)
{
	APlayerStateVG* PlayerState = Cast<APlayerStateVG>(PlayerPawn->GetPlayerState());
	APlayerController* PlayerController = Cast<APlayerController>(PlayerPawn->GetController());
	PlayerState->RemovePlayerLive();
	if(PlayerState->HasLives() && PlayerCanRestart(PlayerController))
		this->RestartPlayer(PlayerController);
}
