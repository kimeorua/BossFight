// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/PropBase.h"
#include "Components/StaticMeshComponent.h"

APropBase::APropBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}
void APropBase::DeactivateProp_Implementation()
{
	// Default implementation does nothing
}
void APropBase::ActivateProp_Implementation()
{
	// Default implementation does nothing
}