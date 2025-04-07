// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/InteractableProp.h"
#include "Components/BoxComponent.h"
#include "Widget/BFWidgetBase.h"

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
	DeactivateProp();
}

void AInteractableProp::BeginPlay()
{
	Super::AActor::BeginPlay();
}

void AInteractableProp::ShowPropUI()
{
	if (PropWidgetClass)
	{
		PropWidget = CreateWidget<UBFWidgetBase>(GetWorld(), PropWidgetClass);

		if (IsValid(PropWidget))
		{
			PropWidget->AddToViewport();
		}
	}
}