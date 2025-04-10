// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/BFGameplayAbility.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"

#include "DebugHelper.h"

void UBFGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EBFAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UBFGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (AbilityActivationPolicy == EBFAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UBFAbilitySystemComponent* UBFGameplayAbility::GetBFAbilitySystemComponentFromActorInfo() const
{
	return Cast<UBFAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
