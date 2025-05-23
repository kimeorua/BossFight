// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "Types/BFEnumType.h"
#include "BFFunctionLibrary.generated.h"

class UBFAbilitySystemComponent;

UCLASS()
class BOSSFIGHT_API UBFFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UBFAbilitySystemComponent* NativeGetWrroirASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library")
	static void RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library", meta = (DisplayName = "Dose Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EBFConfirmType& OutConfirmType);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library", meta = (WorldContext = "WorldContextObject"))
	static void ToggleInputMode(const UObject* WorldContextObject, EBFInputMode InInputMode);

	UFUNCTION(BlueprintPure, Category = "Warrior | Function Library")
	static bool IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn);
};
