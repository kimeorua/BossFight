// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BFPlayerAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Interface/PawnUIInterface.h"
#include "Component/UI/PawnUIComponent.h"
#include "Component/UI/PlayerUIComponent.h"
#include "BFFunctionLibrary.h"
#include "BFGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"

UBFPlayerAttributeSet::UBFPlayerAttributeSet()
{
	InitCurrentSP(0.0f);
	InitMaxSP(0.0f);
	InitWeaponGage(0.0f);
	InitWeaponCount(0.0f);
	InitShieldGage(0.0f);
}

void UBFPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	if (Data.EvaluatedData.Attribute == GetCurrentSPAttribute())
	{
		const float NewCurrentSP = FMath::Clamp(GetCurrentSP(), 0.0f, GetMaxSP());
		SetCurrentSP(NewCurrentSP);

		if (UPlayerUIComponent* PlayerUIComponent = CachedPawnUIInterface->GetPlayerUIComponent())
		{
			PlayerUIComponent->OnCurrentSPChanged.Broadcast(GetCurrentSP() / GetMaxSP());
		}

		if (GetCurrentSP() <= 0.0f)
		{
			UBFFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), BFGameplayTag::Player_Status_Exhaustion);

			if (UBFFunctionLibrary::NativeDoseActorHaveTag(Data.Target.GetAvatarActor(), BFGameplayTag::Player_Status_UseDash))
			{
				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Data.Target.GetAvatarActor(), BFGameplayTag::Player_Event_DashEnd, FGameplayEventData());
			}
		}
		if (GetCurrentSP() >= 20.0f)
		{
			UBFFunctionLibrary::RemoveGameplayTagToActorIfFind(Data.Target.GetAvatarActor(), BFGameplayTag::Player_Status_Exhaustion);
		}
	}
	if (Data.EvaluatedData.Attribute == GetMaxSPAttribute())
	{
		const float NewMaxSP = FMath::Clamp(GetMaxSP(), 0.0f, 200.0f);
		SetMaxSP(NewMaxSP);
	}
	if (Data.EvaluatedData.Attribute == GetWeaponCountAttribute())
	{
		const int NewWeaponCount = FMath::Clamp(GetWeaponCount(), 0.0f, 3.0f);
		SetWeaponCount(NewWeaponCount);
	}
	if (Data.EvaluatedData.Attribute == GetWeaponGageAttribute())
	{
		const float NewWeaponGage = FMath::Clamp(GetWeaponGage(), 0.0f, 100.0f);
		SetWeaponGage(NewWeaponGage);
	}
	if (Data.EvaluatedData.Attribute == GetShieldGageAttribute())
	{
		const float NewShieldGage = FMath::Clamp(GetShieldGage(), 0.0f, 100.0f);
		SetShieldGage(NewShieldGage);
	}
}