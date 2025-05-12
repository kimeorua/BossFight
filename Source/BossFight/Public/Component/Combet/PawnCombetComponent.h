// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PawnExtensionComponent.h"
#include "Types/BFEnumType.h"
#include "PawnCombetComponent.generated.h"

UCLASS()
class BOSSFIGHT_API UPawnCombetComponent : public UPawnExtensionComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ActivateWeaponTrace(EBFEquipType Type);

	UFUNCTION(BlueprintCallable)
	void AttackEnd(EBFEquipType Type);
};
