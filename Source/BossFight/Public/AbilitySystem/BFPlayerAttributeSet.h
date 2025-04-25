// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "BFPlayerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class BOSSFIGHT_API UBFPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UBFPlayerAttributeSet();
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;

	UPROPERTY(BlueprintReadOnly, Category = "Stamina")
	FGameplayAttributeData CurrentSP;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, CurrentSP)

	UPROPERTY(BlueprintReadOnly, Category = "Stamina")
	FGameplayAttributeData MaxSP;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, MaxSP)

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	FGameplayAttributeData WeaponGage;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, WeaponGage)

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	FGameplayAttributeData WeaponCount;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, WeaponCount)

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	FGameplayAttributeData ShieldGage;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, ShieldGage)
};