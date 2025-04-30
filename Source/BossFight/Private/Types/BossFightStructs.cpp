// Fill out your copyright notice in the Description page of Project Settings.


#include "Types/BossFightStructs.h"
#include "AbilitySystem/Ability/BFPlayerAbility.h"

bool FBFAbilitySet::IsVaild() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

bool FBFWeaponCollisionData::IsVaild()
{
	return StartSocket.IsValid() && EndSocket.IsValid();
}
