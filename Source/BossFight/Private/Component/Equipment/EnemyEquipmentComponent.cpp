// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Equipment/EnemyEquipmentComponent.h"
#include "Props/Weapon/EnemyWeapon.h"

void UEnemyEquipmentComponent::RegisterWeapon(TArray<AWeaponBase*> NewWeapon)
{
	for (AWeaponBase* Weapon : NewWeapon)
	{
		if (CurrentWeaponMap.Contains(Weapon->GetEquipType())) { continue; }
		CurrentWeaponMap.Add(Weapon->GetEquipType(), Weapon);
	}
}