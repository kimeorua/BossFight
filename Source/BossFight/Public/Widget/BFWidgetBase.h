// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BFWidgetBase.generated.h"

class UPlayerUIComponent;

UCLASS()
class BOSSFIGHT_API UBFWidgetBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	// ~Begin UUserWidget Interface
	virtual void NativeOnInitialized() override;
	//~End UUserWidget Interface

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Player UIComponent Initalized"))
	void BP_OnOwningHeroUIComponentInitalized(UPlayerUIComponent* OwingPlayerUIComponent);
};
