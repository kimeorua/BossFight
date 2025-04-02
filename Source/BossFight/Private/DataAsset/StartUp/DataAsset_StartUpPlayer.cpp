// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpPlayer.h"
#include "AbilitySystem/Ability/BFPlayerAbility.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"

void UDataAsset_StartUpPlayer::GiveToAbilitySystemComponent(UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FBFAbilitySet& AbilitySet : PlayerAbilitySets)
	{
		if (!AbilitySet.IsVaild()) { continue; }
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}