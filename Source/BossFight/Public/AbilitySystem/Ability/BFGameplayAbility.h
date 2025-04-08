// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BFGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EBFAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

class UBFAbilitySystemComponent;

UCLASS()
class BOSSFIGHT_API UBFGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	// ~ Begin UGameplayAbility
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	EBFAbilityActivationPolicy AbilityActivationPolicy = EBFAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Wrroir | Ability")
	UBFAbilitySystemComponent* GetBFAbilitySystemComponentFromActorInfo() const;
};
