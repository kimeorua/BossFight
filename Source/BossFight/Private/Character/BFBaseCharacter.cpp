// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BFBaseCharacter.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "AbilitySystem/BFAttributeSet.h"

// Sets default values
ABFBaseCharacter::ABFBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	BFAbilitySystemComponent = CreateDefaultSubobject<UBFAbilitySystemComponent>(TEXT("BFAbilitySystemComponent"));
	BFAttributeSet = CreateDefaultSubobject<UBFAttributeSet>(TEXT("BFAttributeSet"));
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
