#pragma once

#include "CoreMinimal.h"

enum class ActionType
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

enum class CameraPathType
{
	Loop,
	Spiral,
	Static,
	Manual
};

enum class CombatStyle
{
	None,
	Mage,
	Archer,
	Knight,
	Warrior
};

enum class FormationType
{
	Frontline,
	Backline
};

enum class ItemRarity
{
	None,
	Common,
	Magic,
	Rare,
	Epic,
	Artifact,
	Legendary
};

enum class ItemSubType
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

enum class ItemType
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

enum class StatType
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

enum class TargetingType
{
	OnlySelf,
	SingleEnemy,
	SingleAlly,
	SingleEnemiesRow,
	SingleAlliesRow,
	AllEnemies,
	AllAllies
};

enum class YesNoQuestions
{
	QuitToMainMenu,
	OverwriteGameSave,
	CreateNewGameSave,
	LoadGame,
	DeleteGameSave
};