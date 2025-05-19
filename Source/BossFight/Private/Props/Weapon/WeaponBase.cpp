// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/Weapon/WeaponBase.h"
#include "Components/BoxComponent.h"

AWeaponBase::AWeaponBase()
{
	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	WeaponCollision->SetupAttachment(GetRootComponent());

	WeaponCollision->SetCollisionProfileName(TEXT("Weapon"));
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	HitedActor = nullptr;
}

void AWeaponBase::AttackTrace()
{
}

void AWeaponBase::OnHitActor(AActor* HitActor)
{
}

void AWeaponBase::AttackEnd()
{
	HitedActor = nullptr;
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AWeaponBase::AttackStart()
{
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}