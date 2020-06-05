// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeBaseVG.h"

#include "Engine/World.h"
#include "TimerManager.h"
#include "PlayerStateVG.h"

void AGameModeBaseVG::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	DefaultPawnClass = MyDefaultPawnClass;
}

void AGameModeBaseVG::RespawnPlayer( APlayerStateVG* PlayerState, APlayerController* PlayerController)
{
	if (PlayerState->HasLives() && PlayerCanRestart(PlayerController))
		this->RestartPlayer(PlayerController);
}

void AGameModeBaseVG::OnPlayerDeath(APawn* PlayerPawn)
{
	APlayerStateVG* PlayerState = Cast<APlayerStateVG>(PlayerPawn->GetPlayerState());
	APlayerController* PlayerController = Cast<APlayerController>(PlayerPawn->GetController());
	PlayerState->RemovePlayerLive();
	PlayerPawn->Destroy();

	FTimerDelegate TimerDelegate;

	TimerDelegate.BindUObject(this, &ThisClass::RespawnPlayer, PlayerState, PlayerController);

	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, TimerDelegate, RespawnTime, false);
	
}


