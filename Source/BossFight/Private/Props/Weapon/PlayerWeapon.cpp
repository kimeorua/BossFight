// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/Weapon/PlayerWeapon.h"

void APlayerWeapon::AssignGrantAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> APlayerWeapon::GetGrantAbilitySpecHandle() const
{
	return GrantAbilitySpecHandles;
}