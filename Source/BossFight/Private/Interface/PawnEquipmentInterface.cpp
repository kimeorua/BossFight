// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/PawnEquipmentInterface.h"

// Add default functionality here for any IPawnEquipmentInterface functions that are not pure virtual.

UPlayerEquipmentComponent* IPawnEquipmentInterface::GetPlayerEquipmentComponent() const
{
	return nullptr;
}

UEnemyEquipmentComponent* IPawnEquipmentInterface::GetEnemyEquipmentComponent() const
{
	return nullptr;
}
