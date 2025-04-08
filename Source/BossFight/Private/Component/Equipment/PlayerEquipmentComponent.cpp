// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Equipment/PlayerEquipmentComponent.h"
#include "Props/Weapon/PlayerWeapon.h"

APlayerWeapon* UPlayerEquipmentComponent::GetPlayerCurrentWeapon(EBFWeaponType Type) const
{
	return Cast<APlayerWeapon>( CurrentWeaponMap.FindRef(Type));
}