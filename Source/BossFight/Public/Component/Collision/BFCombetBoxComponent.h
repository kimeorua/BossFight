// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "BFCombetBoxComponent.generated.h"


UCLASS(ClassGroup = "BF Combet", hidecategories = (Object, LOD, Lighting, TextureStreaming), editinlinenew, meta = (DisplayName = "BF Combet Collision", BlueprintSpawnableComponent))
class BOSSFIGHT_API UBFCombetBoxComponent : public UBoxComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Part", meta = (AllowPrivateAccess = "true"))
	int32 PartNum;

public:
	UBFCombetBoxComponent();
	FORCEINLINE int32 GetPartNum() const { return  PartNum ;}
};