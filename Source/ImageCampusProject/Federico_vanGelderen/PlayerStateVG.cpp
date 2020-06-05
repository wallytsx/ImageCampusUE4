// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateVG.h"
#include "ImageCampusProjectCharacterVG.h"

void APlayerStateVG::RemovePlayerLive()
{
	CurrentPlayerLives -= 1;
}

void APlayerStateVG::BeginPlay()
{
	CurrentPlayerLives = PlayerLives;
}

int APlayerStateVG::GetPlayerLives() const
{
	return CurrentPlayerLives;
}
