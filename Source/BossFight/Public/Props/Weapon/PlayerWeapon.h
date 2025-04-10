// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Props/Weapon/WeaponBase.h"
#include "Types/BossFightStructs.h"
#include "GameplayAbilitySpec.h"
#include "PlayerWeapon.generated.h"

UCLASS()
class BOSSFIGHT_API APlayerWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	void AssignGrantAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	TArray<FGameplayAbilitySpecHandle>GetGrantAbilitySpecHandle() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FBFPlayerWeaponData WeaponData;

private:
	TArray<FGameplayAbilitySpecHandle>GrantAbilitySpecHandles;
};