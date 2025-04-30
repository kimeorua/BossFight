// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interface/PawnUIInterface.h"
#include "Interface/PawnEquipmentInterface.h"
#include "Interface/PawnCombetInterface.h"
#include "BFBaseCharacter.generated.h"

class UBFAbilitySystemComponent;
class UBFAttributeSet;
class UDataAsset_StartUpBase;
class UPawnCombetComponent;

UCLASS()
class BOSSFIGHT_API ABFBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnUIInterface, public IPawnEquipmentInterface, public IPawnCombetInterface
{
	GENERATED_BODY()

public:
	ABFBaseCharacter();

	//~Begin IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End IAbilitySystemInterface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	//~ Begin IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	//~ End IPawnUIInterface

	//~ Begin IPawnEquipmentInterface
	virtual UPawnEquipmentComponent* GetPawnEquipmentComponent() const override;
	//~ End IPawnEquipmentInterface

	// ~Begin IPawnCombetInterface
	virtual UPawnCombetComponent* GetCombetComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBFAbilitySystemComponent* BFAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBFAttributeSet* BFAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data")
	TSoftObjectPtr<UDataAsset_StartUpBase> CharacterStartUpData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combet")
	UPawnCombetComponent* CombetComponent;

public:
	FORCEINLINE UBFAbilitySystemComponent* GetBFAbilitySystemComponent() const { return BFAbilitySystemComponent; }
	FORCEINLINE UBFAttributeSet* GetBFAttributeSet() const { return BFAttributeSet; }
};