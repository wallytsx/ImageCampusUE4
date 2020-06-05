// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawnerWidget.h"
#include "UMG/Public/Components/Button.h"
#include "Engine/World.h"

void UActorSpawnerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	SpawnerButton->OnClicked.AddDynamic(this, &ThisClass::SpawnActor);
}

void UActorSpawnerWidget::SpawnActor()
{
	GetWorld()->SpawnActor<AActor>(SpawnClass,FVector(0,0,200),FRotator(0));
}
