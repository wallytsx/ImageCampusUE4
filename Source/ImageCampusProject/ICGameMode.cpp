// Fill out your copyright notice in the Description page of Project Settings.

#include "ICGameMode.h"

void AICGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	DefaultPawnClass = MyDefaultPawnClass;
}
