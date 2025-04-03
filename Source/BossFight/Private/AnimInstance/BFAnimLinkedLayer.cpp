// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/BFAnimLinkedLayer.h"
#include "AnimInstance/BFPlayerAnimInstance.h"

UBFPlayerAnimInstance* UBFAnimLinkedLayer::GetPlayerAnimInstance() const
{
	return Cast<UBFPlayerAnimInstance>(GetOwningComponent()->GetAnimInstance());
}