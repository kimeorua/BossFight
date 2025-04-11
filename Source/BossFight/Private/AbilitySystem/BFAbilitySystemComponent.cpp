// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "AbilitySystem/Ability/BFPlayerAbility.h"
#include "BFGameplayTags.h"

void UBFAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) { return; }
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) { continue; }

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UBFAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid() || !InInputTag.MatchesTag(BFGameplayTag::InputTag_Hold)) { return; }

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag) && AbilitySpec.IsActive())
		{
			CancelAbilityHandle(AbilitySpec.Handle);
		}
	}
}

void UBFAbilitySystemComponent::GrantPlayerWeaponAbilities(const TArray<FBFAbilitySet>& PlayerWeaponAbilities, TArray<FGameplayAbilitySpecHandle>& OutGrantAbilitySpecHandles, int32 ApplyLevel)
{
	if (PlayerWeaponAbilities.IsEmpty()) { return; }
	for (const FBFAbilitySet& AbilitySet : PlayerWeaponAbilities)
	{
		if (!AbilitySet.IsVaild()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		OutGrantAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UBFAbilitySystemComponent::RemoveGrantPlayerWeaponAbilities(TArray<FGameplayAbilitySpecHandle>& InSpecHandleToRemove)
{
	if (InSpecHandleToRemove.IsEmpty()) return;

	for (FGameplayAbilitySpecHandle& SpecHandle : InSpecHandleToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}
	InSpecHandleToRemove.Empty();
}