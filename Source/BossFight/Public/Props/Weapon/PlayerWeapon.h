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

	virtual void AttackTrace() override;
	virtual void OnHitActor(AActor* HitActor) override;
	virtual void OnHitActor(AActor* HitActor, int32 PartNum);
	virtual void AttackEnd() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FBFWeaponCollisionData CollisionData;

	UFUNCTION()
	void OnWeaponParryOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	APlayerWeapon();

private:
	TArray<FGameplayAbilitySpecHandle>GrantAbilitySpecHandles;
};