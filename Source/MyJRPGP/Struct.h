#pragma once

#include "CoreMinimal.h"
#include "Enum.h"
#include "BattleCharacterBase.h"

struct CharacterInformation
{
	FName CharacterHardcodedName;
	FText CharacterDisplayName;
	int CurrentLevel;
	int AvailableActionPoints;
	ABattleCharacterBase CharacterActorClass;
	UTexture2D CharacterIcon;
	float CurrentHP;
	float CurrentMP;
	TMap<StatType, float> CharacterStats;
	TMap<StatType, float> StatsPerLevel;
	TMap<ItemType, ItemStaticData> CharacterEquipment;
	TSet<ItemSubType> AllowedEquipmentSubtypes;
	TMap<FName, int> CharacterActions;
	TMap<int, NameArray> ActionsPerLevel;
};

struct Encounter
{
	TMap<int, FName> Enemies;
};

struct EnemyInformation
{
	FName EnemyHardcodedName;
	FText EnemyDisplayName;
	int Level;
	int ExperienceReward;
	int GoldReward;
	ABattleCharacterBase CharacterActorClass;
	StatType EnemyStats;
	TMap<float, FName> PossibleLoot;
};

struct ItemDynamicData
{
	int StacksAmount;
	ItemStaticData ItemStaticData;
};

struct ItemStaticData
{
	FName ItemHardcodedName;
	FText ItemDisplayName;
	ItemType ItemType;
	ItemSubType ItemSubtype;
	ItemRarity ItemRarity;
	bool CanBeUsedInBattle;
	bool CanBeUsedInInventory;
	int MaxStackAmount;
	int BuyValue;
	int SellValue;
	FText ItemDescription;
	TMap<StatType, float> ItemStats;
	UTexture2D ItemIcon;
};

struct Level
{
	int ExperienceNeededToReachThisLevel;
};

struct PartySlot
{
	FName CharacterHardcodedName;
	FormationType Formation;
};

struct Action
{
	ActionType ActionType;
	bool IsSecondaryAction;
	FName HardcodedName;
	FText DisplayName;
	FText Description;
	int MaxLevel;
	float BaseCostMP;
	float BaseCostHP;
	float PerLevelCostMP;
	float PerLevelCostHP;
};

struct NameArray
{
	FName ActionName;
};