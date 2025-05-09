// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/Weapon/EnemyWeapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Character/BFBaseCharacter.h"
#include "BFFunctionLibrary.h"
#include "BFGameplayTags.h"

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
		if (UBFFunctionLibrary::NativeDoseActorHaveTag(HitResult.GetActor(), BFGameplayTag::Player_Status_Avoiding))
		{
			Debug::Print("Player Is Avoiding");
		}
		else
		{
			Debug::Print("Player Is Damaged");
			// TODO : 피격한 객체에게 데미지 전달
		}
	}
}