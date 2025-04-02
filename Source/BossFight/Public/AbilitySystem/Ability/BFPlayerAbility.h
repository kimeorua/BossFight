// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/BFGameplayAbility.h"
#include "BFPlayerAbility.generated.h"

class ABFPlayerCharacter;
class ABFPlayerController;

UCLASS()
class BOSSFIGHT_API UBFPlayerAbility : public UBFGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	ABFPlayerCharacter* GetPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	ABFPlayerController* GetPlayerControllerFromActorInfo();

private:
	TWeakObjectPtr<ABFPlayerCharacter> CachedPlayerCharacter;
	TWeakObjectPtr<ABFPlayerController> CachedPlayerController;
};
