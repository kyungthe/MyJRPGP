// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomEnum.generated.h"

UENUM()
enum class EActionType : uint8
{
	None,		
	Attack,
	Defend,
	Items,
	Flee,
	Magic,
	Moves,
	Deathblow
};

UENUM()
enum class ECameraPathType : uint8
{
	Loop,
	Spiral,
	Static,
	Manual
};

UENUM()
enum class ECombatStyle : uint8
{
	None,
	Mage,
	Archer,
	Knight,
	Warrior
};

UENUM()
enum class EFormationType : uint8
{
	Frontline,
	Backline
};

UENUM()
enum class EItemRarity : uint8
{
	None,
	Common,
	Magic,
	Rare,
	Epic,
	Artifact,
	Legendary
};

UENUM()
enum class EItemSubType : uint8
{
	None,
	Sword,
	Staff,
	Bow,
	Axe,
	Dagger,
	HeavyArmor,
	LeatherArmor,
	RobeArmor,
	Ring,
	Necklace,
	Medicine
};

UENUM()
enum class EItemType : uint8
{
	None,
	Weapon,
	Armor,
	Helmet,
	Gloves,
	Boots,
	Accessory,
	Potion
};

UENUM()
enum class ECharacterStatType : uint8
{
	None,
	HP,
	MP,
	Power,
	Defence,
	CriticalRate,
	CriticalPower,
	Initiative,
	Evasion
};

UENUM()
enum class ETargetingType : uint8
{
	OnlySelf,
	SingleEnemy,
	SingleAlly,
	SingleEnemiesRow,
	SingleAlliesRow,
	AllEnemies,
	AllAllies
};

UENUM()
enum class EYesNoQuestions : uint8
{
	QuitToMainMenu,
	OverwriteGameSave,
	CreateNewGameSave,
	LoadGame,
	DeleteGameSave
};

class MYJRPGP_API CustomEnum
{
public:
	CustomEnum();
	~CustomEnum();
};
