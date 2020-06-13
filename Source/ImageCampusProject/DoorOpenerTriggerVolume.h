// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "DoorOpenerTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class IMAGECAMPUSPROJECT_API ADoorOpenerTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaSeconds) override;

	bool bShouldOpenDoor = false;

public:

	ADoorOpenerTriggerVolume();

	// overlap begin function
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	// overlap end function
	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, meta = (ToolTip = "Door Actor"))
	AActor* DoorActor;

	UPROPERTY(EditAnywhere, meta = (ToolTip = "TargetPoint location"))
	AActor* DoorTargetLocation;

	UFUNCTION()
	void OnAssetLoadingEnd();
};
