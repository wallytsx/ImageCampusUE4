// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageGameInstance.h"

void UImageGameInstance::SetAssetLoaderInstance(AAssetLoaderManager* NewManager)
{
	AssetLoaderManager = NewManager;
}

AAssetLoaderManager* UImageGameInstance::GetAssetLoaderInstance()
{
	return AssetLoaderManager;
}
