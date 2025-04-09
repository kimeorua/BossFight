// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/BFPlayerAnimInstance.h"
#include "Character/BFPlayerCharacter.h"
#include "BFFunctionLibrary.h"
#include "BFGameplayTags.h"

void UBFPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningPlayerCharacter = Cast<ABFPlayerCharacter>(OwningCharacter);
	}
}

void UBFPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (OwningPlayerCharacter)
	{
		bIsEquipWeapon = UBFFunctionLibrary::NativeDoseActorHaveTag(OwningPlayerCharacter, BFGameplayTag::Player_WeaponEquip);
	}
}