// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BFBaseCharacter.generated.h"

class UBFAbilitySystemComponent;
class UBFAttributeSet;

UCLASS()
class BOSSFIGHT_API ABFBaseCharacter : public ACharacter, public IAbilitySystemInterface
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBFAbilitySystemComponent* BFAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBFAttributeSet* BFAttributeSet;

public:
	FORCEINLINE UBFAbilitySystemComponent* GetBFAbilitySystemComponent() const { return BFAbilitySystemComponent; }
	FORCEINLINE UBFAttributeSet* GetBFAttributeSet() const { return BFAttributeSet; }
};
