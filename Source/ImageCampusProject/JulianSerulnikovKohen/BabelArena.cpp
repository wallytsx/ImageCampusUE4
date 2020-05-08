// Fill out your copyright notice in the Description page of Project Settings.

#include "BabelArena.h"

void ABabelArena::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	DefaultPawnClass = DefaultGladiator;
}