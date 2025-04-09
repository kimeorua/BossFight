// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Equipment/PawnEquipmentComponent.h"
#include "Props/Weapon/WeaponBase.h"

void UPawnEquipmentComponent::RegisterWeapon(TArray<AWeaponBase*> NewWeapon)
{
	if (!CurrentWeaponMap.IsEmpty())
	{
		for (TPair Pair : CurrentWeaponMap)
		{
			Pair.Value->Destroy();
		}
		CurrentWeaponMap.Empty();
	}
	for (AWeaponBase* Weapon : NewWeapon)
	{
		CurrentWeaponMap.Add(Weapon->GetWeaponType(), Weapon);
	}
}