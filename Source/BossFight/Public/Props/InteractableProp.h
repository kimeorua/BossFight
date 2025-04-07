// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Props/PropBase.h"
#include "Interface/InteractablePropInterface.h"
#include "InteractableProp.generated.h"

class UBoxComponent;
class UBFWidgetBase;

UCLASS()
class BOSSFIGHT_API AInteractableProp : public APropBase, public IInteractablePropInterface
{
	GENERATED_BODY()
public:
	AInteractableProp();
	virtual void Interact() override;
	virtual void InteractEnd() override;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* CollisionBox;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	TSubclassOf<UBFWidgetBase>PropWidgetClass;

	UPROPERTY()
	UBFWidgetBase* PropWidget;

	void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void ShowPropUI();
};