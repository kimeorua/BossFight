// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Equipment/PlayerEquipmentComponent.h"
#include "Props/Weapon/PlayerWeapon.h"
#include "BFFunctionLibrary.h"
#include "BFGameplayTags.h"
#include "Character/BFPlayerCharacter.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"

APlayerWeapon* UPlayerEquipmentComponent::GetPlayerCurrentWeapon(EBFWeaponType Type) const
{
	return Cast<APlayerWeapon>( CurrentWeaponMap.FindRef(Type));
}

void UPlayerEquipmentComponent::RegisterWeapon(TArray<AWeaponBase*> NewWeapon)
{
	ABFPlayerCharacter* Owner = Cast<ABFPlayerCharacter>(GetOwner());
	UBFAbilitySystemComponent* ASC = Owner->GetBFAbilitySystemComponent();
	if (!CurrentWeaponMap.IsEmpty())
	{
		for (TPair Pair : CurrentWeaponMap)
		{
			APlayerWeapon* PlayerWeapon = Cast<APlayerWeapon>(Pair.Value);
			TArray<FGameplayAbilitySpecHandle> SpecHandles = PlayerWeapon->GetGrantAbilitySpecHandle();
			ASC->RemoveGrantPlayerWeaponAbilities(SpecHandles);

			Pair.Value->Destroy();
		}
		CurrentWeaponMap.Empty();
	}
	for (AWeaponBase* Weapon : NewWeapon)
	{
		CurrentWeaponMap.Add(Weapon->GetWeaponType(), Weapon);
		APlayerWeapon* PlayerWeapon = Cast<APlayerWeapon>(Weapon);
		TArray<FGameplayAbilitySpecHandle> SpecHandles;
		ASC->GrantPlayerWeaponAbilities(PlayerWeapon->WeaponData.WeaponAbilities, SpecHandles);
		PlayerWeapon->AssignGrantAbilitySpecHandles(SpecHandles);
	}
	UBFFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), BFGameplayTag::Player_WeaponEquip);
}