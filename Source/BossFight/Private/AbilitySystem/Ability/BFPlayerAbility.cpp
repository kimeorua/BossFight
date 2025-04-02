// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/BFPlayerAbility.h"
#include "Controller/BFPlayerController.h"
#include "Character/BFPlayerCharacter.h"

ABFPlayerCharacter* UBFPlayerAbility::GetPlayerCharacterFromActorInfo()
{
	if (!CachedPlayerCharacter.IsValid())
	{
		CachedPlayerCharacter = Cast<ABFPlayerCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedPlayerCharacter.IsValid() ? CachedPlayerCharacter.Get() : nullptr;
}

ABFPlayerController* UBFPlayerAbility::GetPlayerControllerFromActorInfo()
{
	if (!CachedPlayerController.IsValid())
	{
		CachedPlayerController = Cast<ABFPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedPlayerController.IsValid() ? CachedPlayerController.Get() : nullptr;
}