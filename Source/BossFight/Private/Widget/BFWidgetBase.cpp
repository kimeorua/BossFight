// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/BFWidgetBase.h"
#include "Interface/PawnUIInterface.h"

void UBFWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UPlayerUIComponent* PlayerUIComponent = PawnUIInterface->GetPlayerUIComponent())
		{
			BP_OnOwningHeroUIComponentInitalized(PlayerUIComponent);
		}
	}
}