// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "Types/BossFightStructs.h"
#include "DataAsset_StartUpPlayer.generated.h"

/**
 * 
 */
UCLASS()
class BOSSFIGHT_API UDataAsset_StartUpPlayer : public UDataAsset_StartUpBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UBFAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FBFAbilitySet> PlayerAbilitySets;
};
