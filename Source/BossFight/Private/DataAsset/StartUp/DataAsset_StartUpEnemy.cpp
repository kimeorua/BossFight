// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpEnemy.h"
#include "AbilitySystem/Ability/BFEnemyAbility.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"

void UDataAsset_StartUpEnemy::GiveToAbilitySystemComponent(UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (TSubclassOf<UBFEnemyAbility>& EnemyAbility : EnemyAbilities)
	{
		if (!IsValid(EnemyAbility)) { continue; }

		FGameplayAbilitySpec AbilitySpec(EnemyAbility);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}