// Fill out your copyright notice in the Description page of Project Settings.


#include "BFGameplayTags.h"

namespace BFGameplayTag
{
	// Input Tags
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interaction, "InputTag.Interaction");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold, "InputTag.Hold");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_Dash, "InputTag.Hold.Dash");

	// Player Tags
	UE_DEFINE_GAMEPLAY_TAG(Player_WeaponEquip, "Player.WeaponEquip");
}