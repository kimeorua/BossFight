// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Types/BossFightStructs.h"
#include "BFAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class BOSSFIGHT_API UBFAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	void GrantPlayerWeaponAbilities(const TArray<FBFAbilitySet>& PlayerWeaponAbilities, TArray<FGameplayAbilitySpecHandle>& OutGrantAbilitySpecHandles, int32 ApplyLevel = 1);

	void RemoveGrantPlayerWeaponAbilities(TArray<FGameplayAbilitySpecHandle>& InSpecHandleToRemove);
};
