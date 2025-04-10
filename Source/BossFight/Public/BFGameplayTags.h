// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "NativeGameplayTags.h"

namespace BFGameplayTag
{
	// Input Tags
	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Interaction);
	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_ComboAttack);

	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Hold);
	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Hold_Dash);

	// Player Tags
	BOSSFIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_WeaponEquip);
}