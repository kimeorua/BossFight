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
	virtual void RegisterWeapon(TArray<AWeaponBase*> NewWeapon);

	FORCEINLINE AWeaponBase* GetCurrentWeapon(EBFEquipType Type) const { return CurrentWeaponMap.FindRef(Type); }

protected:
	TMap<EBFEquipType, AWeaponBase*> CurrentWeaponMap;
};