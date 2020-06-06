// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorManagerWidget.h"
#include "Kismet/GameplayStatics.h"
#include "ImageCampusProject/Actors/ActorContainer.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Blueprint/WidgetTree.h"

void UActorManagerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, AActorContainer::StaticClass(), Actors);

	for (AActor* Actor : Actors)
	{
		AActorContainer* ActorContainer = Cast<AActorContainer>(Actor);
		ActorContainers.Add(ActorContainer);

		UActorManagerEntry* Entry = CreateWidget<UButton>(UButton::StaticClass());

		Entry->Setup(this, ActorContainer);

		VBoxButtons->AddChild(Entry);
	}
}

void UActorManagerWidget::OnEntryClicked(UActorManagerEntry* Entry)
{
	if (CurrentActorContainer != nullptr)
	{
		CurrentActorContainer->Disable();
	}
	CurrentActorContainer = Entry->GetActorContainer();
	CurrentActorContainer->Enable();
}

