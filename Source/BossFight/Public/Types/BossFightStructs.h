// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "BossFightStructs.generated.h"

class UBFPlayerAbility;

USTRUCT(BlueprintType)
struct FBFAbilitySet 
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBFPlayerAbility> AbilityToGrant;

	bool IsVaild()const;
};