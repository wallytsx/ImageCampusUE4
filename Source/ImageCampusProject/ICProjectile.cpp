// Fill out your copyright notice in the Description page of Project Settings.

#include "ICProjectile.h"
#include "Components/StaticMeshComponent.h"

/*AICProjectile::AICProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}*/

AICProjectile::AICProjectile()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}
