// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ImageGameInstance.generated.h"

class AAssetLoaderManager;

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API UImageGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	void SetAssetLoaderInstance(AAssetLoaderManager* NewManager);
	AAssetLoaderManager* GetAssetLoaderInstance();
private:
	UPROPERTY()
	AAssetLoaderManager* AssetLoaderManager = nullptr;

};
