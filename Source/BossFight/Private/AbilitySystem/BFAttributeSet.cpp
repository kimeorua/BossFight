// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BFAttributeSet.h"
#include "GameplayEffectExtension.h"

UBFAttributeSet::UBFAttributeSet()
{
	InitCurrentHP(1.0f);
	InitMaxHP(1.0f);
}

void UBFAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHPAttribute())
	{
		const float NewCurrentHP = FMath::Clamp(GetCurrentHP(), 0.0f, GetMaxHP());
		SetCurrentHP(NewCurrentHP);
	}

	if (Data.EvaluatedData.Attribute == GetMaxHPAttribute())
	{
		const float NewMaxHP = FMath::Clamp(GetMaxHP(), 0.0f, 200.0f);
		SetMaxHP(NewMaxHP);
	}
}
