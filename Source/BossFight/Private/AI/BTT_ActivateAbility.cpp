// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTT_ActivateAbility.h"
#include "Character/BFBaseCharacter.h"
#include "Controller/EnemyAIController.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_ActivateAbility::UBTT_ActivateAbility()
{
	NodeName = "Activte Ability";
	bNotifyTick = true;
}

EBTNodeResult::Type UBTT_ActivateAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ABFBaseCharacter* Character = Cast<ABFBaseCharacter>(OwnerComp.GetAIOwner()->GetCharacter());

	if (UBFAbilitySystemComponent* ASC =  Character->GetBFAbilitySystemComponent())
	{
		ASC->TryActivateAbilitiesByTag(TagContainer);
		return EBTNodeResult::InProgress;
	}
	else
	{
		return EBTNodeResult::Failed;
	} 
}

void UBTT_ActivateAbility::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	AEnemyAIController* AI = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	if (AI->GetBlackboardComponent()->GetValueAsEnum(AI->AIState) == uint8(EBFEnemyAIState::Idle))
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}
}