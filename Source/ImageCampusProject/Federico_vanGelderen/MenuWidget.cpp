// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "UMG/Public/Components/PanelWidget.h"
#include "UMG/Public/Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMenuWidget::PlayGame() const
{
	UGameplayStatics::OpenLevel(this, "ThirdPersonExampleMap");
}

void UMenuWidget::ExitGame()
{
	//FGenericPlatformMisc::RequestExit(false);
	UKismetSystemLibrary::QuitGame(this, nullptr,EQuitPreference::Quit,true);
}
