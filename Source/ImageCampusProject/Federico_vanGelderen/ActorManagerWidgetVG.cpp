// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorManagerWidgetVG.h"
#include "ImageCampusProject/Federico_vanGelderen//Actors/ActorContainerVG.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Blueprint/WidgetTree.h"
#include "ButtonVG.h"

void UActorManagerWidgetVG::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, AActorContainerVG::StaticClass(), Actors);

	AActorContainerVG* ActorContainer;
	ActorContainer = Cast<AActorContainerVG>(Actors[0]);

	if (ActorContainer)
	{
		for (AActor* Actor : ActorContainer->GetManagedActors())
		{
			//ActorContainers.Add(Cast<AActorContainerVG>(Actor));
			ManagedActors.Add(Actor);

			UButtonVG* Button = WidgetTree->ConstructWidget<UButtonVG>(UButtonVG::StaticClass());
			Button->SetActor(Actor);
			Button->OnClicked.AddDynamic(this, &ThisClass::OnButtonClicked);
			Button->OnClicked.AddDynamic(Button, &UButtonVG::OnButtonClicked);

			//VBoxButtons->AddChild(Button);
			VBoxButtons->AddChildToVerticalBox(Button);

			Buttons.Add(Button);
		}
	}
}

void UActorManagerWidgetVG::OnButtonClicked()
{
	for (AActor* Actor : ManagedActors)
	{
		Actor->SetActorEnableCollision(false);
		Actor->SetActorHiddenInGame(true);
		Actor->SetActorTickEnabled(false);
	}
}