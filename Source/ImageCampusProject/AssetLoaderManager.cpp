// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetLoaderManager.h"
#include "ImageGameInstance.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

// Sets default values
AAssetLoaderManager::AAssetLoaderManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAssetLoaderManager::BeginPlay()
{
	Super::BeginPlay();
	
	UImageGameInstance* ImageGameInstance = Cast<UImageGameInstance>(GetGameInstance());
	ImageGameInstance->SetAssetLoaderInstance(this);

}

void AAssetLoaderManager::OnAssetsLoaded()
{
	OnAssetsLoadedDelegate.Broadcast();
}

void AAssetLoaderManager::AddAssetToLoad(TSoftObjectPtr<UObject> AssetToBeLoaded)
{
	AssetsToLoad.Add(AssetToBeLoaded);
}

void AAssetLoaderManager::LoadAssets(bool bAsyncLoad /*= true*/)
{
	TArray<FSoftObjectPath> ItemsToStream;
	
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	for (int32 i = 0; i < AssetsToLoad.Num(); ++i)
	{
		ItemsToStream.AddUnique(AssetsToLoad[i].ToStringReference());
	}
	Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &AAssetLoaderManager::OnAssetsLoaded));
}

// Called every frame
//void AAssetLoaderManager::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

