// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BFPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "Component/Input/BFInputComponent.h"
#include "BFGameplayTags.h"
#include "DataAsset/StartUp/DataAsset_StartUpPlayer.h"
#include "AbilitySystem/BFAbilitySystemComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interface/InteractablePropInterface.h"
#include "Component/UI/PlayerUIComponent.h"
#include "Component/Equipment/PlayerEquipmentComponent.h"

ABFPlayerCharacter::ABFPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 450.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 55.0f, 65.0f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 250.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;

	PlayerUIComponent = CreateDefaultSubobject<UPlayerUIComponent>(TEXT("PlayerUIComponent"));
	PlayerEquipmentComponent = CreateDefaultSubobject<UPlayerEquipmentComponent>(TEXT("PlayerEquipmentComponent"));
}

void ABFPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABFPlayerCharacter::PossessedBy(AController* NewController)
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

UPawnUIComponent* ABFPlayerCharacter::GetPawnUIComponent() const
{
	return GetPlayerUIComponent();
}

UPlayerUIComponent* ABFPlayerCharacter::GetPlayerUIComponent() const
{
	return PlayerUIComponent;
}

UPawnEquipmentComponent* ABFPlayerCharacter::GetPawnEquipmentComponent() const
{
	return GetPlayerEquipmentComponent();
}

UPlayerEquipmentComponent* ABFPlayerCharacter::GetPlayerEquipmentComponent() const
{
	return PlayerEquipmentComponent;
}

void ABFPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forget to assgin a vaild data asset as input config"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(SubSystem);

	SubSystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UBFInputComponent* BFInputComponent = CastChecked<UBFInputComponent>(PlayerInputComponent);

	BFInputComponent->BindNativeInputAction(InputConfigDataAsset, BFGameplayTag::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	BFInputComponent->BindNativeInputAction(InputConfigDataAsset, BFGameplayTag::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	BFInputComponent->BindNativeInputAction(InputConfigDataAsset, BFGameplayTag::InputTag_Interaction, ETriggerEvent::Started, this, &ThisClass::Input_Interection);

	BFInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void ABFPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (MovementVector.Y != 0.0f)
	{
		const FVector ForwardDirection = MovementRotator.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.0f)
	{
		const FVector RightDirection = MovementRotator.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABFPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.0f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y != 0.0f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABFPlayerCharacter::Input_Interection()
{
	FHitResult HitResult;

	UKismetSystemLibrary::SphereTraceSingleForObjects
	(
		GetWorld(),
		GetActorLocation(),
		GetActorLocation(),
		InteractionDistance,
		ObjectType,
		false,
		TArray<AActor*>(),
		bShowPersistenDebugShape ? EDrawDebugTrace::Persistent : EDrawDebugTrace::None,
		HitResult,
		true
	);

	if (HitResult.GetActor())
	{
		if (IInteractablePropInterface* InteractableProp = Cast<IInteractablePropInterface>(HitResult.GetActor()))
		{
			InteractableProp->Interact();
			PlayerUIComponent->SetInteractableProp(HitResult.GetActor());
		}
		else { return; }
	}
	else { return; }
}

void ABFPlayerCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	BFAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ABFPlayerCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	BFAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}