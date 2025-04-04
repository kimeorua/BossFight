// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/InteractableProp.h"
#include "Components/BoxComponent.h"

AInteractableProp::AInteractableProp()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(GetRootComponent());

	CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
}

void AInteractableProp::Interact()
{
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ActivateProp();
}

void AInteractableProp::InteractEnd()
{
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AInteractableProp::BeginPlay()
{
	Super::AActor::BeginPlay();
}
