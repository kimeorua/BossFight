// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/BFGameplayAbility.h"
#include "BFEnemyAbility.generated.h"

class UEnemyEquipmentComponent;
class ABFEnemyCharacter;

UCLASS()
class BOSSFIGHT_API UBFEnemyAbility : public UBFGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	ABFEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	UEnemyEquipmentComponent* GetEnemyEquipmentComponentFromActorInfo();

private:
	TWeakObjectPtr<ABFEnemyCharacter> CachedEnemyCharacter;
};