// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonVG.h"

void UButtonVG::OnButtonClicked()
{
	MyActor->SetActorEnableCollision(false);
	MyActor->SetActorHiddenInGame(false);
	MyActor->SetActorTickEnabled(false);
}

void UButtonVG::SetActor(AActor* Actor)
{
	MyActor = Actor;
}
