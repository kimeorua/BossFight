// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PropBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class BOSSFIGHT_API APropBase : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

public:	
	// Sets default values for this actor's properties
	APropBase();

	UFUNCTION(BlueprintNativeEvent)
	void ActivateProp();
};
