// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PawnCombetComponent.h"
#include "Interface/PawnEquipmentInterface.h"
#include "Component/Equipment/PlayerEquipmentComponent.h"
#include "Interface/WeaponInterface.h"
#include "Props/Weapon/WeaponBase.h"

void UPawnCombetComponent::ActivateWeaponTrace(EBFEquipType Type)
{
	UPawnEquipmentComponent* EquipmentComponent = Cast<IPawnEquipmentInterface>(GetOwner())->GetPawnEquipmentComponent();
	IWeaponInterface* WeaponInterface = Cast<IWeaponInterface>(EquipmentComponent->GetCurrentWeapon(Type));
	WeaponInterface->AttackTrace();
}

void UPawnCombetComponent::AttackEnd(EBFEquipType Type)
{
	UPawnEquipmentComponent* EquipmentComponent = Cast<IPawnEquipmentInterface>(GetOwner())->GetPawnEquipmentComponent();
	IWeaponInterface* WeaponInterface = Cast<IWeaponInterface>(EquipmentComponent->GetCurrentWeapon(Type));
	WeaponInterface->AttackEnd();
}