// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Props/PropBase.h"
#include "Types/BFEnumType.h"
#include "Interface/WeaponInterface.h"
#include "WeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class BOSSFIGHT_API AWeaponBase : public APropBase, public IWeaponInterface
{
	GENERATED_BODY()
	
public:
	AWeaponBase();

	FORCEINLINE EBFEquipType GetEquipType() const { return EquipType; }

	virtual void AttackTrace() override;

	virtual void OnHitActor(AActor* HitActor) override;

	virtual void AttackEnd() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EBFEquipType EquipType = EBFEquipType::EquipRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* WeaponCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WeaponSocket;

	AActor* HitedActor;
};
