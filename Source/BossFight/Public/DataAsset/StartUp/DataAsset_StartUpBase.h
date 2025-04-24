// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpBase.generated.h"

class UBFGameplayAbility;
class UBFAbilitySystemComponent;
class UGameplayEffect;

UCLASS()
class BOSSFIGHT_API UDataAsset_StartUpBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UBFGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UBFGameplayAbility>> ActivateOnTriggerdAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray < TSubclassOf<UGameplayEffect>> StartUpGameplayEffects;

	void GrantAbilities(const TArray<TSubclassOf<UBFGameplayAbility>>& InAbilityToGive, UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};