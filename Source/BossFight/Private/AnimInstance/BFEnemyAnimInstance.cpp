// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/BFEnemyAnimInstance.h"
#include "Character/BFEnemyCharacter.h"

void UBFEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningEnemyCharacter = Cast<ABFEnemyCharacter>(OwningCharacter);
	}
}

void UBFEnemyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (OwningEnemyCharacter)
	{
		bIsStrafing = (AIState == EBFEnemyAIState::Strafing) ? true : false;
	}
}