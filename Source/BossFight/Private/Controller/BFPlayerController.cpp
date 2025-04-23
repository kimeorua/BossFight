// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/BFPlayerController.h"

ABFPlayerController::ABFPlayerController()
{
	TeamID = FGenericTeamId(0);
}

FGenericTeamId ABFPlayerController::GetGenericTeamId() const
{
	return TeamID;
}