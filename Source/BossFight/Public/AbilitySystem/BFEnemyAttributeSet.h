// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "BFEnemyAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class BOSSFIGHT_API UBFEnemyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBFEnemyAttributeSet();
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;

	UPROPERTY(BlueprintReadOnly, Category = "PartHP")
	FGameplayAttributeData Part1_HP;
	ATTRIBUTE_ACCESSORS(UBFEnemyAttributeSet, Part1_HP)

	UPROPERTY(BlueprintReadOnly, Category = "PartHP")
	FGameplayAttributeData Part1_MaxHP;
	ATTRIBUTE_ACCESSORS(UBFEnemyAttributeSet, Part1_MaxHP)

	UPROPERTY(BlueprintReadOnly, Category = "PartHP")
	FGameplayAttributeData Part2_HP;
	ATTRIBUTE_ACCESSORS(UBFEnemyAttributeSet, Part2_HP)

	UPROPERTY(BlueprintReadOnly, Category = "PartHP")
	FGameplayAttributeData Part2_MaxHP;
	ATTRIBUTE_ACCESSORS(UBFEnemyAttributeSet, Part2_MaxHP)
};