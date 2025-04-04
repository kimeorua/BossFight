// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Props/PropBase.h"
#include "Interface/InteractablePropInterface.h"
#include "InteractableProp.generated.h"

class UBoxComponent;

UCLASS()
class BOSSFIGHT_API AInteractableProp : public APropBase, public IInteractablePropInterface
{
	GENERATED_BODY()
public:
	AInteractableProp();
	virtual void Interact() override;
	UFUNCTION(BlueprintCallable)
	virtual void InteractEnd() override;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* CollisionBox;

	void BeginPlay() override;
};