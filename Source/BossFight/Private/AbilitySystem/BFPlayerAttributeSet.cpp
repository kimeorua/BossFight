// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BFPlayerAttributeSet.h"
#include "GameplayEffectExtension.h"

UBFPlayerAttributeSet::UBFPlayerAttributeSet()
{
	InitCurrentSP(0.0f);
	InitMaxSP(0.0f);
	InitWeaponGage(0.0f);
	InitWeaponCount(0.0f);
	InitShieldGage(0.0f);
}

void UBFPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentSPAttribute())
	{
		const float NewCurrentSP = FMath::Clamp(GetCurrentSP(), 0.0f, GetMaxSP());
		SetCurrentSP(NewCurrentSP);
	}
	if (Data.EvaluatedData.Attribute == GetMaxSPAttribute())
	{
		const float NewMaxSP = FMath::Clamp(GetMaxSP(), 0.0f, 200.0f);
		SetMaxSP(NewMaxSP);
	}
	if (Data.EvaluatedData.Attribute == GetWeaponCountAttribute())
	{
		const int NewWeaponCount = FMath::Clamp(GetWeaponCount(), 0.0f, 3.0f);
		SetWeaponCount(NewWeaponCount);
	}
	if (Data.EvaluatedData.Attribute == GetWeaponGageAttribute())
	{
		const float NewWeaponGage = FMath::Clamp(GetWeaponGage(), 0.0f, 100.0f);
		SetWeaponGage(NewWeaponGage);
	}
	if (Data.EvaluatedData.Attribute == GetShieldGageAttribute())
	{
		const float NewShieldGage = FMath::Clamp(GetShieldGage(), 0.0f, 100.0f);
		SetShieldGage(NewShieldGage);
	}
}