// Fill out your copyright notice in the Description page of Project Settings.


#include "BFGameplayTags.h"

namespace BFGameplayTag
{
	// Input Tags
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interaction, "InputTag.Interaction");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ComboAttack, "InputTag.ComboAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_PowerAttack, "InputTag.PowerAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_DerivAttack, "InputTag.DerivAttack");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold, "InputTag.Hold");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_Dash, "InputTag.Hold.Dash");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_ChargeAttack, "InputTag.Hold.ChargeAttack");

	// Player Tags
	UE_DEFINE_GAMEPLAY_TAG(Player_WeaponEquip, "Player.WeaponEquip");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo, "Player.Ability.Combo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_1, "Player.Ability.Combo.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_2, "Player.Ability.Combo.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_3, "Player.Ability.Combo.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_4, "Player.Ability.Combo.4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Deriv, "Player.Ability.Combo.Deriv");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_PowerAttack, "Player.Ability.PowerAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_PowerAttack_Combo1, "Player.Ability.PowerAttack.Combo1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_PowerAttack_Combo2, "Player.Ability.PowerAttack.Combo2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_PowerAttack_Combo3, "Player.Ability.PowerAttack.Combo3");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ChargeAttack, "Player.Ability.ChargeAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ChargeAttack_Charging, "Player.Ability.ChargeAttack.Charging");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ChargeAttack_Attack, "Player.Ability.ChargeAttack.Attack");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo2, "Player.Status.ReadyCombo2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo3, "Player.Status.ReadyCombo3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo4, "Player.Status.ReadyCombo4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Charge, "Player.Status.Charge");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Charge_1, "Player.Status.Charge.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Charge_2, "Player.Status.Charge.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Derivable, "Player.Status.Derivable");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_UseDash, "Player.Status.UseDash");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_DashSPDawn, "Player.Status.DashSPDawn");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Exhaustion, "Player.Status.Exhaustion");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ReadyCombo, "Player.Event.ReadyCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EndCombo, "Player.Event.EndCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Charge1, "Player.Event.Charge1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Charge2, "Player.Event.Charge2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ActivateChargeAttack, "Player.Event.ActivateChargeAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_DashEnd, "Player.Event.DashEnd");

	// Enemy Tags
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Attack, "Enemy.Ability.Attack");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Attack_1, "Enemy.Ability.Attack.1");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Attack_2, "Enemy.Ability.Attack.2");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Attack_3, "Enemy.Ability.Attack.3");
}