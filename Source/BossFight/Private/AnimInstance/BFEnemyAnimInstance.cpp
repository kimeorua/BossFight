// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/BFEnemyAnimInstance.h"
#include "Character/BFEnemyCharacter.h"
#include "Controller/EnemyAIController.h"
#include "Types/BFEnumType.h"

void UBFEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningEnemyCharacter = Cast<ABFEnemyCharacter>(OwningCharacter);
		OwningAIController = Cast<AEnemyAIController>(OwningEnemyCharacter->GetController());
	}
}

void UBFEnemyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (OwningEnemyCharacter)
	{
		if (OwningAIController)
		{
			bIsStrafing = (OwningAIController->GetAIState() == EBFEnemyAIState::Strafing);
		}
	}
}