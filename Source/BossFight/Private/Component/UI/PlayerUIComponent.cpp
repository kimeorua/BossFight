// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UI/PlayerUIComponent.h"
#include "Interface/InteractablePropInterface.h"

void UPlayerUIComponent::SetInteractableProp(AActor* Prop)
{
	if (IInteractablePropInterface* InteractableProp = Cast<IInteractablePropInterface>(Prop))
	{
		InteractablePropInterface = InteractableProp;
	}
}

void UPlayerUIComponent::EndInteract()
{
	InteractablePropInterface->InteractEnd();
	InteractablePropInterface = nullptr;
}
