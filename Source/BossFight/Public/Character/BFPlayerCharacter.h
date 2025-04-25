// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BFBaseCharacter.h"
#include "GameplayTagContainer.h"
#include "BFPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
class UPlayerUIComponent;
class UPlayerEquipmentComponent;
class UBFPlayerAttributeSet;

struct FInputActionValue;

UCLASS()
class BOSSFIGHT_API ABFPlayerCharacter : public ABFBaseCharacter
{
	GENERATED_BODY()

public:
	ABFPlayerCharacter();
	FORCEINLINE UBFPlayerAttributeSet* GetBFPlayerAttributeSet() const { return BFPlayerAttributeSet; }

protected:
	//~ Begin APawn Interface.
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	//~ Begin IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UPlayerUIComponent* GetPlayerUIComponent() const override;
	//~ End IPawnUIInterface

	//~ Begin IPawnEquipmentInterface
	virtual UPawnEquipmentComponent* GetPawnEquipmentComponent() const override;
	virtual UPlayerEquipmentComponent* GetPlayerEquipmentComponent() const override;
	//~ End IPawnEquipmentInterface

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UIComponent", meta = (AllowPrivateAccess = "true"))
	UPlayerUIComponent* PlayerUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EquipmentComponent", meta = (AllowPrivateAccess = "true"))
	UPlayerEquipmentComponent* PlayerEquipmentComponent;

#pragma endregion

#pragma region Inputs

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset = nullptr;

	UPROPERTY()
	FVector2D SwitchDirection = FVector2D::ZeroVector;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	void Input_Interection();

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

#pragma endregion

#pragma region Interaction
	UPROPERTY(EditDefaultsOnly, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	float InteractionDistance = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	TArray<TEnumAsByte<	EObjectTypeQuery>> ObjectType;

	UPROPERTY(EditDefaultsOnly, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	bool bShowPersistenDebugShape = false;
#pragma endregion

#pragma region PlayerAttributeSet
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem", meta = (AllowPrivateAccess = "true"))
	UBFPlayerAttributeSet* BFPlayerAttributeSet;
#pragma endregion
};
