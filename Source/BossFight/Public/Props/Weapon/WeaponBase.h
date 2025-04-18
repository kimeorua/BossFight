// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Props/PropBase.h"
#include "Types/BFEnumType.h"
#include "WeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class BOSSFIGHT_API AWeaponBase : public APropBase
{
	GENERATED_BODY()
	
public:
	AWeaponBase();

	FORCEINLINE EBFEquipType GetEquipType() const { return EquipType; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EBFEquipType EquipType = EBFEquipType::EquipRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* WeaponCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WeaponSocket;
};
