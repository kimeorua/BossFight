// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/Weapon/PlayerWeapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Component/Collision/BFCombetBoxComponent.h"

#include "DebugHelper.h"

void APlayerWeapon::AssignGrantAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> APlayerWeapon::GetGrantAbilitySpecHandle() const
{
	return GrantAbilitySpecHandles;
}

void APlayerWeapon::AttackTrace()
{
	if (!CollisionData.IsVaild()) { return; }

	FVector Start = Mesh->GetSocketLocation(CollisionData.StartSocket);
	FVector End = Mesh->GetSocketLocation(CollisionData.EndSocket);
	FVector BoxSize = WeaponCollision->GetScaledBoxExtent();

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel3));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Cast<AActor>(GetOwner()));

	FHitResult HitResult;

	UKismetSystemLibrary::BoxTraceSingleForObjects(
		GetWorld(),
		Start, 
		End, 
		BoxSize, 
		GetActorRotation(),
		ObjectTypes, 
		false, 
		ActorsToIgnore,
		CollisionData.bIsShow ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
		HitResult, 
		true);

	if (HitResult.GetActor() && HitResult.GetComponent())
	{
		if (UBFCombetBoxComponent* HitComponent = Cast<UBFCombetBoxComponent>(HitResult.GetComponent()))
		{
			Debug::Print(FString::FromInt(HitComponent->GetPartNum()));
		}
	}
}