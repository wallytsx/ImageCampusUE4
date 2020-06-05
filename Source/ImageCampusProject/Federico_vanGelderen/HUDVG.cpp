// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDVG.h"

void AHUDVG::BeginPlay()
{
	Super::BeginPlay();

	SpawnerButtonWidget = CreateWidget<UActorSpawnerWidget>(Cast<APlayerController>(GetOwner()), ButtonWidgetClass);
	SpawnerButtonWidget->AddToViewport();
}
