// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "BFBaseAnimInstance.generated.h"


UCLASS()
class BOSSFIGHT_API UBFBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	bool DoseOwnerHasTag(FGameplayTag TagToCheck) const;
};
