// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BFBaseCharacter.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "AbilitySystem/BFAttributeSet.h"
#include "Component/Combet/PawnCombetComponent.h"
#include "MotionWarpingComponent.h"

#include "DebugHelper.h"

// Sets default values
ABFBaseCharacter::ABFBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	BFAbilitySystemComponent = CreateDefaultSubobject<UBFAbilitySystemComponent>(TEXT("BFAbilitySystemComponent"));
	BFAttributeSet = CreateDefaultSubobject<UBFAttributeSet>(TEXT("BFAttributeSet"));

	CombetComponent = CreateDefaultSubobject<UPawnCombetComponent>(TEXT("CombetComponent"));

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));
}

UAbilitySystemComponent* ABFBaseCharacter::GetAbilitySystemComponent() const
{
	return GetBFAbilitySystemComponent();
}

void ABFBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (BFAbilitySystemComponent)
	{
		BFAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgat to assign start up data to %s"), *GetName());
	}
}

UPawnUIComponent* ABFBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}

UPawnEquipmentComponent* ABFBaseCharacter::GetPawnEquipmentComponent() const
{
	return nullptr;
}

UPawnCombetComponent* ABFBaseCharacter::GetCombetComponent() const
{
	return CombetComponent;
}
