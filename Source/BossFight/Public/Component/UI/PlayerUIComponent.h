// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/PawnUIComponent.h"
#include "PlayerUIComponent.generated.h"

class IInteractablePropInterface;

UCLASS()
class BOSSFIGHT_API UPlayerUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
	
private:
	IInteractablePropInterface* InteractablePropInterface;

public:
	FORCEINLINE void SetInteractableProp(AActor* Prop);

	UFUNCTION(BlueprintCallable)
	void EndInteract();
};