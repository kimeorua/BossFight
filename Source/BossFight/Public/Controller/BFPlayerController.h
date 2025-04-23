// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "BFPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSFIGHT_API ABFPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:
	ABFPlayerController();

	//~Begin IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~End IGenericTeamAgentInterface

private:
	FGenericTeamId TeamID;
};