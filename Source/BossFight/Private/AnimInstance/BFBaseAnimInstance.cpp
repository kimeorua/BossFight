// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/BFBaseAnimInstance.h"
#include "BFFunctionLibrary.h"

bool UBFBaseAnimInstance::DoseOwnerHasTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UBFFunctionLibrary::NativeDoseActorHaveTag(OwningPawn, TagToCheck);
	}
	return false;
}