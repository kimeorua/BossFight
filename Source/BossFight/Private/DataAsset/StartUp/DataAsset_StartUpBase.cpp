// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "AbilitySystem/Ability/BFGameplayAbility.h"

void UDataAsset_StartUpBase::GiveToAbilitySystemComponent(UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ActivateOnTriggerdAbilities, InASCToGive, ApplyLevel);

	/*if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass) continue;

			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext());
		}
	}*/
}

void UDataAsset_StartUpBase::GrantAbilities(const TArray<TSubclassOf<UBFGameplayAbility>>& InAbilityToGive, UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilityToGive.IsEmpty())
	{
		return;
	}
	for (const TSubclassOf<UBFGameplayAbility>& Ability : InAbilityToGive)
	{
		if (!Ability) { continue; }

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		InASCToGive->GiveAbility(AbilitySpec);
	}
}