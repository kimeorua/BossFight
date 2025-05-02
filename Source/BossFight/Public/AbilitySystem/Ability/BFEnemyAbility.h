// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/BFGameplayAbility.h"
#include "Types/BFEnumType.h"
#include "BFEnemyAbility.generated.h"

class UEnemyEquipmentComponent;
class ABFEnemyCharacter;
class AEnemyAIController;

UCLASS()
class BOSSFIGHT_API UBFEnemyAbility : public UBFGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	ABFEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	UEnemyEquipmentComponent* GetEnemyEquipmentComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "BossFight | Ability")
	AEnemyAIController* GetAIControllerFromActorInfo();

	UFUNCTION(BlueprintCallable, Category = "BossFight | Ability", meta = (ExpandEnumAsExecs = "OutConfirmType"))
	void ChangeAIState(EBFEnemyAIState AIState, EBFConfirmType& OutConfirmType);

private:
	TWeakObjectPtr<ABFEnemyCharacter> CachedEnemyCharacter;
	TWeakObjectPtr<AEnemyAIController> CachedEnemyAIController;
};