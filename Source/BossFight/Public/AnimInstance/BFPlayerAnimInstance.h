// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/BFCharacterAnimInstance.h"
#include "BFPlayerAnimInstance.generated.h"

class ABFPlayerCharacter;

UCLASS()
class BOSSFIGHT_API UBFPlayerAnimInstance : public UBFCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data | Refrence")
	ABFPlayerCharacter* OwningPlayerCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data | Refrence")
	bool bIsEquipWeapon;
};
