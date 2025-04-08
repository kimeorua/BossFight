// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnEquipmentInterface.generated.h"

class UPawnEquipmentComponent;
class UPlayerEquipmentComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnEquipmentInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOSSFIGHT_API IPawnEquipmentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UPawnEquipmentComponent* GetPawnEquipmentComponent() const = 0;
	virtual UPlayerEquipmentComponent* GetPlayerEquipmentComponent() const;
};
