// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/BFEnemyAbility.h"
#include "Character/BFEnemyCharacter.h"
#include "Component/Equipment/EnemyEquipmentComponent.h"
#include "Controller/EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

ABFEnemyCharacter* UBFEnemyAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedEnemyCharacter.IsValid())
	{
		CachedEnemyCharacter = Cast<ABFEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedEnemyCharacter.IsValid() ? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyEquipmentComponent* UBFEnemyAbility::GetEnemyEquipmentComponentFromActorInfo()
{
	if (IPawnEquipmentInterface* PawnEquipmentInterface = Cast<IPawnEquipmentInterface>(GetEnemyCharacterFromActorInfo()))
	{
		return PawnEquipmentInterface->GetEnemyEquipmentComponent();
	}
	else { return nullptr; }
}

AEnemyAIController* UBFEnemyAbility::GetAIControllerFromActorInfo()
{
	if (!CachedEnemyCharacter.IsValid())
	{
		CachedEnemyCharacter = Cast<ABFEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	if (!CachedEnemyAIController.IsValid())
	{
		CachedEnemyAIController = Cast<AEnemyAIController>(CachedEnemyCharacter->GetController());
	}
	return CachedEnemyAIController.IsValid() ? CachedEnemyAIController.Get() : nullptr;
}

void UBFEnemyAbility::ChangeAIState(EBFEnemyAIState AIState, EBFConfirmType& OutConfirmType)
{
	if (AEnemyAIController* AI = GetAIControllerFromActorInfo())
	{
		AI->GetBlackboardComponent()->SetValueAsEnum(AI->AIState, uint8(AIState));
		EBFConfirmType::Yes;
	}
	else { EBFConfirmType::No; }
}
