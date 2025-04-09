// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Equipment/PlayerEquipmentComponent.h"
#include "Props/Weapon/PlayerWeapon.h"
#include "BFFunctionLibrary.h"
#include "BFGameplayTags.h"

APlayerWeapon* UPlayerEquipmentComponent::GetPlayerCurrentWeapon(EBFWeaponType Type) const
{
	return Cast<APlayerWeapon>( CurrentWeaponMap.FindRef(Type));
}

void UPlayerEquipmentComponent::RegisterWeapon(TArray<AWeaponBase*> NewWeapon)
{
	Super::RegisterWeapon(NewWeapon);

	UBFFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), BFGameplayTag::Player_WeaponEquip);
}