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
enum class EBFEquipType : uint8
{
	EquipLeft,
	EquipRight
};

UENUM(BlueprintType)
enum class EBFEnemyAIState : uint8
{
	Idle,
	Strafing,
	Chase,
	Attack
};