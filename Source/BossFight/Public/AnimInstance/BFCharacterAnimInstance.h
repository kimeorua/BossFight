// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/BFBaseAnimInstance.h"
#include "BFCharacterAnimInstance.generated.h"

class ABFBaseCharacter;
class UCharacterMovementComponent;

UCLASS()
class BOSSFIGHT_API UBFCharacterAnimInstance : public UBFBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;

protected:
	UPROPERTY()
	ABFBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data | LocomationData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data | LocomationData")
	bool bHasAcceleration;
};
