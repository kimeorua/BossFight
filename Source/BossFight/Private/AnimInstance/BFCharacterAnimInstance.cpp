// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/BFCharacterAnimInstance.h"
#include "Character/BFBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBFCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ABFBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UBFCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f;
}