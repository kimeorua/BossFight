// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/BFBaseAnimInstance.h"
#include "BFAnimLinkedLayer.generated.h"

class UBFPlayerAnimInstance;

UCLASS()
class BOSSFIGHT_API UBFAnimLinkedLayer : public UBFBaseAnimInstance
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintPure, meta = (NotBlueprintThreadSafe))
	UBFPlayerAnimInstance* GetPlayerAnimInstance() const;
};
