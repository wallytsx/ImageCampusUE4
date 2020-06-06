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
		ActorContainers.Add(Cast<AActorContainer>(Actor));

		UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());

		Button->OnClicked.AddDynamic(this, &ThisClass::OnButtonClicked<1>);

		VBoxButtons->AddChild(Button);
		Buttons.Add(Button);
	}
}

template<int Index>
void UActorManagerWidget::OnButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("OnButtonClicked - %i"), Index);
}

void UActorManagerWidget::OnEntryClicked(UActorManagerEntry* Entry)
{
	if (CurrentActorContainer != nullptr)
	{
		CurrentActorContainer->Deactivate();
	}
	CurrentActorContainer = Entry->GetActorContainer();
	CurrentActorContainer->Activate();
}
