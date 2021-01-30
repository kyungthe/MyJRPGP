 //Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomEnum.h"
#include "CustomStruct.generated.h"

/**
 * 
 */
class MYJRPGP_API CustomStruct
{
public:
	CustomStruct();
	~CustomStruct();
};

USTRUCT()
struct FNameArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName ActionName;
};

USTRUCT()
struct FItemStaticData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName ItemHardcodedName;

	UPROPERTY()
	FText ItemDisplayName;

	UPROPERTY()
	EItemType ItemType;

	UPROPERTY()
	EItemSubType ItemSubtype;

	UPROPERTY()
	EItemRarity ItemRarity;

	UPROPERTY()
	bool CanBeUsedInBattle;

	UPROPERTY()
	bool CanBeUsedInInventory;

	UPROPERTY()
	int MaxStackAmount;

	UPROPERTY()
	int BuyValue;

	UPROPERTY()
	int SellValue;

	UPROPERTY()
	FText ItemDescription;

	UPROPERTY()
	TMap<ECharacterStatType, float> ItemStats;

	UPROPERTY()
	class UTexture2D* ItemIcon;
};

USTRUCT()
struct FCharacterInformation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName CharacterHardcodedName;

	UPROPERTY()
	FText CharacterDisplayName;

	UPROPERTY()
	int CurrentLevel;

	UPROPERTY()
	int AvailableActionPoints;

	UPROPERTY()
	class ABattleCharacterBase* CharacterActorClass;

	UPROPERTY()
	class UTexture2D* CharacterIcon;

	UPROPERTY()
	float CurrentHP;

	UPROPERTY()
	float CurrentMP;

	UPROPERTY()
	TMap<ECharacterStatType, float> CharacterStats;

	UPROPERTY()
	TMap<ECharacterStatType, float> StatsPerLevel;

	UPROPERTY()
	TMap<EItemType, FItemStaticData> CharacterEquipment;

	UPROPERTY()
	TSet<EItemSubType> AllowedEquipmentSubtypes;

	UPROPERTY()
	TMap<FName, int> CharacterActions;

	UPROPERTY()
	TMap<int, FNameArray> ActionsPerLevel;
};

USTRUCT()
struct FEncounter
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<int, FName> Enemies;
};

USTRUCT()
struct FEnemyInformation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName EnemyHardcodedName;

	UPROPERTY()
	FText EnemyDisplayName;

	UPROPERTY()
	int Level;

	UPROPERTY()
	int ExperienceReward;

	UPROPERTY()
	int GoldReward;

	UPROPERTY()
	class ABattleCharacterBase* CharacterActorClass;

	UPROPERTY()
	ECharacterStatType EnemyStats;

	UPROPERTY()
	TMap<float, FName> PossibleLoot;
};

USTRUCT()
struct FItemDynamicData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int StacksAmount;

	UPROPERTY()
	FItemStaticData ItemStaticData;
};

USTRUCT()
struct FCharacterLevel
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int ExperienceNeededToReachThisLevel;
};

USTRUCT()
struct FPartySlot
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName CharacterHardcodedName;

	UPROPERTY()
	EFormationType Formation;
};

USTRUCT()
struct FAction
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	EActionType ActionType;

	UPROPERTY()
	bool IsSecondaryAction;

	UPROPERTY()
	FName HardcodedName;

	UPROPERTY()
	FText DisplayName;

	UPROPERTY()
	FText Description;

	UPROPERTY()
	int MaxLevel;

	UPROPERTY()
	float BaseCostMP;

	UPROPERTY()
	float BaseCostHP;

	UPROPERTY()
	float PerLevelCostMP;

	UPROPERTY()
	float PerLevelCostHP;
};

