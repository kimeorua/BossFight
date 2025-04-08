// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Equipment/PawnEquipmentComponent.h"
#include "Props/Weapon/WeaponBase.h"

void UPawnEquipmentComponent::RegisterWeapon(AWeaponBase* NewWeapon)
{
	if (!CurrentWeaponMap.IsEmpty())
	{
		CurrentWeaponMap.Empty();
	}
	if (NewWeapon)
	{
		CurrentWeaponMap.Add(NewWeapon->GetWeaponType(), NewWeapon);
	}
}