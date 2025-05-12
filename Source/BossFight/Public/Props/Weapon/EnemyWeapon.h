// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Props/Weapon/WeaponBase.h"
#include "Types/BossFightStructs.h"
#include "EnemyWeapon.generated.h"

/**
 * 
 */
UCLASS()
class BOSSFIGHT_API AEnemyWeapon : public AWeaponBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Type")
	bool bHasMesh = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FBFWeaponCollisionData CollisionData;

public:
	virtual void AttackTrace() override;
	virtual void OnHitActor(AActor* HitActor) override;
	virtual void AttackEnd() override;
};