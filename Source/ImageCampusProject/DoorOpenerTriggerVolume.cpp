// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpenerTriggerVolume.h"
#include "ImageCampusProjectCharacter.h"
#include "ImageGameInstance.h"
#include "AssetLoaderManager.h"

void ADoorOpenerTriggerVolume::Tick(float DeltaSeconds)
{
	if (!bShouldOpenDoor)
		return;

	FVector NewLocation = FMath::VInterpTo(DoorActor->GetActorLocation(), DoorTargetLocation->GetActorLocation(), DeltaSeconds, 0.5f);
	DoorActor->SetActorLocation(NewLocation);
}

ADoorOpenerTriggerVolume::ADoorOpenerTriggerVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &ADoorOpenerTriggerVolume::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADoorOpenerTriggerVolume::OnOverlapEnd);
	PrimaryActorTick.bCanEverTick = true;
}

void ADoorOpenerTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	AImageCampusProjectCharacter* CastedActor = Cast<AImageCampusProjectCharacter>(OtherActor);

	if (CastedActor)
	{
		//AAssetLoaderManager* AssetLoader = Cast<UImageGameInstance>(GetGameInstance())->GetAssetLoaderInstance();

		AAssetLoaderManager* AssetLoader = Cast<AAssetLoaderManager>(AAssetLoaderManager::StaticClass()->GetDefaultObject());
		AssetLoader->OnAssetsLoadedDelegate.AddUObject(this, &ADoorOpenerTriggerVolume::OnAssetLoadingEnd);
		AssetLoader->LoadAssets();
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("AssetLoadStart"));
	}
}

void ADoorOpenerTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{

}

void ADoorOpenerTriggerVolume::OnAssetLoadingEnd()
{
	bShouldOpenDoor = true;
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("AssetLoadEnd"));
}
