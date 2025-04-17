// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Equipment/PawnEquipmentComponent.h"
#include "EnemyEquipmentComponent.generated.h"

UCLASS()
class BOSSFIGHT_API UEnemyEquipmentComponent : public UPawnEquipmentComponent
{
	GENERATED_BODY()
public:
	virtual void RegisterWeapon(TArray<AWeaponBase*> NewWeapon) override;
};
