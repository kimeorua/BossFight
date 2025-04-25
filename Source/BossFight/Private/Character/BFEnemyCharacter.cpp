// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BFEnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Component/Equipment/EnemyEquipmentComponent.h"
#include "Component/UI/EnemyUIComponent.h"
#include "DataAsset/StartUp/DataAsset_StartUpEnemy.h"
#include "AbilitySystem/BFEnemyAttributeSet.h"

ABFEnemyCharacter::ABFEnemyCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 250.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;

	EnemyEquipmentComponent = CreateDefaultSubobject<UEnemyEquipmentComponent>(TEXT("EnemyEquipmentComponent"));
	EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>(TEXT("EnemyUIComponent"));

	BFEnemyAttributeSet = CreateDefaultSubobject<UBFEnemyAttributeSet>(TEXT("BFEnemyAttributeSet"));
}

void ABFEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABFEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpBase* LodedData = CharacterStartUpData.LoadSynchronous())
		{
			LodedData->GiveToAbilitySystemComponent(BFAbilitySystemComponent);
		}
	}
}

UPawnUIComponent* ABFEnemyCharacter::GetPawnUIComponent() const
{
	return GetEnemyUIComponent();
}

UEnemyUIComponent* ABFEnemyCharacter::GetEnemyUIComponent() const
{
	return EnemyUIComponent;
}

UPawnEquipmentComponent* ABFEnemyCharacter::GetPawnEquipmentComponent() const
{
	return GetEnemyEquipmentComponent();
}

UEnemyEquipmentComponent* ABFEnemyCharacter::GetEnemyEquipmentComponent() const
{
	return EnemyEquipmentComponent;
}
