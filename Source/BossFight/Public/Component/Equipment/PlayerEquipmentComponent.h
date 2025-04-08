// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Equipment/PawnEquipmentComponent.h"
#include "PlayerEquipmentComponent.generated.h"

class APlayerWeapon;

UCLASS()
class BOSSFIGHT_API UPlayerEquipmentComponent : public UPawnEquipmentComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Equipment")
	APlayerWeapon* GetPlayerCurrentWeapon(EBFWeaponType Type) const;
};
