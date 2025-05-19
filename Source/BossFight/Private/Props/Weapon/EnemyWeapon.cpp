// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/Weapon/EnemyWeapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Character/BFBaseCharacter.h"
#include "BFFunctionLibrary.h"
#include "BFGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "DebugHelper.h"

void AEnemyWeapon::AttackTrace()
{
	if (!CollisionData.IsVaild()) { return; }

	FVector Start, End, BoxSize;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Cast<AActor>(GetOwner()));

	FHitResult HitResult;

	BoxSize = WeaponCollision->GetScaledBoxExtent();

	if (bHasMesh)
	{
		Start = Mesh->GetSocketLocation(CollisionData.StartSocket);
		End = Mesh->GetSocketLocation(CollisionData.EndSocket);
	}
	else
	{
		ABFBaseCharacter* EnemyOwner = Cast<ABFBaseCharacter>(GetOwner());
		Start = EnemyOwner->GetMesh()->GetSocketLocation(CollisionData.StartSocket);
		End = EnemyOwner->GetMesh()->GetSocketLocation(CollisionData.EndSocket);
	}
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

	if (HitResult.GetActor() && UBFFunctionLibrary::IsTargetPawnHostile(Cast<APawn>(GetOwner()),  Cast<APawn>(HitResult.GetActor())))
	{
		OnHitActor(HitResult.GetActor());
	}
}

void AEnemyWeapon::OnHitActor(AActor* HitActor)
{
	if (HitedActor == HitActor) { return; }

	HitedActor = HitActor;
	if (UBFFunctionLibrary::NativeDoseActorHaveTag(HitedActor, BFGameplayTag::Player_Status_Avoiding)) { return; }
	if (UBFFunctionLibrary::NativeDoseActorHaveTag(HitedActor, BFGameplayTag::Player_Status_ParrySuccess)) 
	{ 
		Debug::Print("Parr!!"); 
		return; 
	}
	FGameplayEventData Data;
	Data.Instigator = GetOwner();
	Data.Target = HitActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), BFGameplayTag::Shared_Event_OnDamaged, Data);
	if (UBFFunctionLibrary::NativeDoseActorHaveTag(GetOwner(), BFGameplayTag::Enemy_Status_Attack_Normal))
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitedActor, BFGameplayTag::Player_Event_OnHit_Normal, FGameplayEventData());
		Debug::Print("Hit Normal");
	}
	else if (UBFFunctionLibrary::NativeDoseActorHaveTag(GetOwner(), BFGameplayTag::Enemy_Status_Attack_Power))
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitedActor, BFGameplayTag::Player_Event_OnHit_Power, FGameplayEventData());
		Debug::Print("Hit Power");
	}
}