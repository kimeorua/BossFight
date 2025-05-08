// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BFAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Interface/PawnUIInterface.h"
#include "Component/UI/PawnUIComponent.h"
#include "Component/UI/PlayerUIComponent.h"

UBFAttributeSet::UBFAttributeSet()
{
	InitCurrentHP(1.0f);
	InitMaxHP(1.0f);
	InitCurrentStun(0.0f);
}

void UBFAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	if (Data.EvaluatedData.Attribute == GetCurrentHPAttribute())
	{
		const float NewCurrentHP = FMath::Clamp(GetCurrentHP(), 0.0f, GetMaxHP());
		SetCurrentHP(NewCurrentHP);

		if (UPlayerUIComponent* PlayerUIComponent = CachedPawnUIInterface->GetPlayerUIComponent())
		{
			PlayerUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHP() / GetMaxHP());
		}
	}

	if (Data.EvaluatedData.Attribute == GetCurrentStunAttribute())
	{
		const float NewMaxHP = FMath::Clamp(GetCurrentStun(), 0.0f, 100.0f);
		SetCurrentStun(NewMaxHP);
	}
}