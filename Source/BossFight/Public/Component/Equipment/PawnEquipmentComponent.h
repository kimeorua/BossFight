// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PawnExtensionComponent.h"
#include "Types/BFEnumType.h"
#include "PawnEquipmentComponent.generated.h"

class AWeaponBase;

UCLASS()
class BOSSFIGHT_API UPawnEquipmentComponent : public UPawnExtensionComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Equipment")
	void RegisterWeapon(AWeaponBase* NewWeapon);

protected:
	TMap<EBFWeaponType, AWeaponBase*> CurrentWeaponMap;
};
