// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "DataAsset_StartUpEnemy.generated.h"

class UBFEnemyAbility;

UCLASS()
class BOSSFIGHT_API UDataAsset_StartUpEnemy : public UDataAsset_StartUpBase
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UBFEnemyAbility>> EnemyAbilities;
};