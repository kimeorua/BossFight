// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/BFEnemyAbility.h"
#include "Character/BFEnemyCharacter.h"
#include "Component/Equipment/EnemyEquipmentComponent.h"

ABFEnemyCharacter* UBFEnemyAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedEnemyCharacter.IsValid())
	{
		CachedEnemyCharacter = Cast<ABFEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedEnemyCharacter.IsValid() ? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyEquipmentComponent* UBFEnemyAbility::GetEnemyEquipmentComponentFromActorInfo()
{
	if (IPawnEquipmentInterface* PawnEquipmentInterface = Cast<IPawnEquipmentInterface>(GetEnemyCharacterFromActorInfo()))
	{
		return PawnEquipmentInterface->GetEnemyEquipmentComponent();
	}
	else { return nullptr; }
}