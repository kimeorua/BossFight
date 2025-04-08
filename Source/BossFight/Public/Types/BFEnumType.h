#pragma once

UENUM()
enum class EBFConfirmType : uint8
{
	Yes,
	No
};
UENUM(BlueprintType)
enum class EBFInputMode : uint8
{
	GameOnly,
	UIOnly
};

UENUM(BlueprintType)
enum class EBFWeaponType : uint8
{
	WeaponLeft,
	WeaponRight
};