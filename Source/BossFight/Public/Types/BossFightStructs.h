// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "AnimInstance/BFAnimLinkedLayer.h"
#include "AttributeSet.h"
#include "BossFightStructs.generated.h"

class UBFPlayerAbility;
class UBFAnimLinkedLayer;
class UInputMappingContext;
class UAttributeSet;

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

USTRUCT(BlueprintType)
struct FBFPlayerWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FBFAbilitySet>WeaponAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* InputContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBFAnimLinkedLayer> WeaponAnimLayerClass;
};

USTRUCT(BlueprintType)
struct FBFWeaponCollisionData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName StartSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName EndSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsShow = false;

	bool IsVaild();
};