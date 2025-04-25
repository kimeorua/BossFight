// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BFEnemyAttributeSet.h"
#include "GameplayEffectExtension.h"

UBFEnemyAttributeSet::UBFEnemyAttributeSet()
{
	InitPart1_HP(100.0f);
	InitPart1_MaxHP(1000.0f);
	InitPart2_HP(100.0f);
	InitPart2_MaxHP(1000.0f);
}

void UBFEnemyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetPart1_HPAttribute())
	{
		const float NewPart1_HP = FMath::Clamp(GetPart1_HP(), 0.0f, GetPart1_MaxHP());
		SetPart1_HP(NewPart1_HP);
	}
	if (Data.EvaluatedData.Attribute == GetPart2_HPAttribute())
	{
		const float NewPart2_HP = FMath::Clamp(GetPart2_HP(), 0.0f, GetPart2_MaxHP());
		SetPart2_HP(NewPart2_HP);
	}
}