// Fill out your copyright notice in the Description page of Project Settings.


#include "BFGameplayTags.h"

namespace BFGameplayTag
{
	// Input Tags
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interaction, "InputTag.Interaction");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ComboAttack, "InputTag.ComboAttack");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold, "InputTag.Hold");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_Dash, "InputTag.Hold.Dash");

	// Player Tags
	UE_DEFINE_GAMEPLAY_TAG(Player_WeaponEquip, "Player.WeaponEquip");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo, "Player.Ability.Combo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_1, "Player.Ability.Combo.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_2, "Player.Ability.Combo.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_3, "Player.Ability.Combo.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_4, "Player.Ability.Combo.4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo2, "Player.Status.ReadyCombo2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo3, "Player.Status.ReadyCombo3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo4, "Player.Status.ReadyCombo4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ReadyCombo, "Player.Event.ReadyCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EndCombo, "Player.Event.EndCombo");
}