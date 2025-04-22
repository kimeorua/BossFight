// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/BFCharacterAnimInstance.h"
#include "Types/BFEnumType.h"
#include "BFEnemyAnimInstance.generated.h"

class ABFEnemyCharacter;

UCLASS()
class BOSSFIGHT_API UBFEnemyAnimInstance : public UBFCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data | Refrence")
	ABFEnemyCharacter* OwningEnemyCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data | Refrence")
	bool bIsStrafing = false;

private:
	EBFEnemyAIState AIState = EBFEnemyAIState::Idle;
};