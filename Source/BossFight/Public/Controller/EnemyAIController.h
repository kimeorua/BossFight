// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
class UBehaviorTree;

UCLASS()
class BOSSFIGHT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AEnemyAIController();
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

public:
	//-------------------------------------------블랙보드 키에 접근시 사용할 이름들-------------------------------------------//
	static const FName TargetActor;
	static const FName AIState;
	//-------------------------------------------블랙보드 키에 접근시 사용할 이름들-------------------------------------------//

	UFUNCTION(BlueprintCallable)
	EBFEnemyAIState GetAIState();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	virtual void OnEnemyPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAIPerceptionComponent* EnemyPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAISenseConfig_Sight* AISenseConfig_Sight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBehaviorTree* BehaviorTree = nullptr;
};