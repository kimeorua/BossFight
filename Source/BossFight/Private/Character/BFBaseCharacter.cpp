// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BFBaseCharacter.h"

// Sets default values
ABFBaseCharacter::ABFBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}
