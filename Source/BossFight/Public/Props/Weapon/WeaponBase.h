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

	FORCEINLINE EBFWeaponType GetWeaponType() const { return WeaponType; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EBFWeaponType WeaponType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* WeaponCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WeaponSocket;
};
