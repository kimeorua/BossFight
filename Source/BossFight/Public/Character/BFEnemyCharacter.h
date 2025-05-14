// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BFBaseCharacter.h"
#include "Types/BFEnumType.h"
#include "BFEnemyCharacter.generated.h"

class UEnemyEquipmentComponent;
class UEnemyUIComponent;
class UBFEnemyAttributeSet;
class UBFCombetBoxComponent;

UCLASS()
class BOSSFIGHT_API ABFEnemyCharacter : public ABFBaseCharacter
{
	GENERATED_BODY()
	
public:
	ABFEnemyCharacter();

	UFUNCTION(BlueprintCallable)
	void SetCollisionSet(EBFEnemyAttackType Type, UBFCombetBoxComponent* Collision);

	UFUNCTION(BlueprintCallable)
	void AttackCollisionChange(EBFEnemyAttackType Type, ECollisionResponse NewECR);

protected:
	//~ Begin APawn Interface.
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	//~ Begin IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UEnemyUIComponent* GetEnemyUIComponent() const override;
	//~ End IPawnUIInterface

	//~ Begin IPawnEquipmentInterface
	virtual UPawnEquipmentComponent* GetPawnEquipmentComponent() const override;
	virtual UEnemyEquipmentComponent* GetEnemyEquipmentComponent() const override;
	//~ End IPawnEquipmentInterface

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EquipmentComponent", meta = (AllowPrivateAccess = "true"))
	UEnemyEquipmentComponent* EnemyEquipmentComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI Component", meta = (AllowPrivateAccess = "true"))
	UEnemyUIComponent* EnemyUIComponent;
#pragma endregion

#pragma region EnemyAttributeSet
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem", meta = (AllowPrivateAccess = "true"))
	UBFEnemyAttributeSet* BFEnemyAttributeSet;
#pragma endregion

#pragma region EnemyCollision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EnemyCollision", meta = (AllowPrivateAccess = "true"))
	TMap<EBFEnemyAttackType, UBFCombetBoxComponent*> CollisionSet;
#pragma endregion
};