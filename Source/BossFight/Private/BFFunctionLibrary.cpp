// Fill out your copyright notice in the Description page of Project Settings.


#include "BFFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"

UBFAbilitySystemComponent* UBFFunctionLibrary::NativeGetWrroirASCFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<UBFAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UBFFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UBFAbilitySystemComponent* ASC = NativeGetWrroirASCFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UBFFunctionLibrary::RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove)
{
	UBFAbilitySystemComponent* ASC = NativeGetWrroirASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UBFFunctionLibrary::NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UBFAbilitySystemComponent* ASC = NativeGetWrroirASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UBFFunctionLibrary::BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EBFConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoseActorHaveTag(InActor, TagToCheck) ? EBFConfirmType::Yes : EBFConfirmType::No;
}