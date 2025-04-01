// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/BFGameModeBase.h"

ABFGameModeBase::ABFGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}