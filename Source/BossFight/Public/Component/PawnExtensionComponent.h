// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BOSSFIGHT_API UPawnExtensionComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T Template Parmeter get  GetPawn must be derived form APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T Template Parmeter get  GetController must be derived form AController");
		GetOwningPawn<APawn>()->GetController<T>();
	}
};
