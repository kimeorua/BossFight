// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/EnemyAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Types/BFEnumType.h"

const FName AEnemyAIController::TargetActor(TEXT("TargetActor"));
const FName AEnemyAIController::AIState(TEXT("AIState"));


AEnemyAIController::AEnemyAIController()
{
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("EnemySenseConfig_Sight");
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Sight->SightRadius = 1200.0f;
	AISenseConfig_Sight->LoseSightRadius = 0.0f;
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 90.0f;

	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("EnemyPerceptionComponent");
	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());

	EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::OnEnemyPerceptionUpdate);

	SetGenericTeamId(FGenericTeamId(1));
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnToCheck = Cast<const APawn>(&Other);
	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

	if (OtherTeamAgent && OtherTeamAgent->GetGenericTeamId() < GetGenericTeamId())
	{
		return ETeamAttitude::Hostile;
	}
	return ETeamAttitude::Friendly;
}

EBFEnemyAIState AEnemyAIController::GetAIState()
{
	if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	{
		return EBFEnemyAIState(GetBlackboardComponent()->GetValueAsEnum(AIState));
	}
	else
	{
		return EBFEnemyAIState::None;
	}
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(BehaviorTree))
	{
		RunBehaviorTree(BehaviorTree);
	}

	if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	{
		BlackboardComponent->SetValueAsEnum(AIState, uint8(EBFEnemyAIState::Idle));
	}
}

void AEnemyAIController::OnEnemyPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	{
		if (!BlackboardComponent->GetValueAsObject(TargetActor))
		{
			if (Stimulus.WasSuccessfullySensed() && Actor)
			{
				BlackboardComponent->SetValueAsObject(TargetActor, Actor);
			}
		}
	}
}