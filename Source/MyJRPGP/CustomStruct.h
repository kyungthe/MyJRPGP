 //Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomEnum.h"
#include <Engine/DataTable.h>
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

USTRUCT(BlueprintType)
struct FNameArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> ActionName;
};

USTRUCT(BlueprintType)
struct FItemStaticData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemHardcodedName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemSubType ItemSubtype;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemRarity ItemRarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanBeUsedInBattle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanBeUsedInInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStackAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SellValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECharacterStatType, float> ItemStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* ItemIcon;
};

USTRUCT(BlueprintType)
struct FCharacterInformation : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CharacterHardcodedName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText CharacterDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AvailableActionPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ABattleCharacterBase* CharacterActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* CharacterIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECharacterStatType, float> CharacterStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECharacterStatType, float> StatsPerLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EItemType, FItemStaticData> CharacterEquipment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<EItemSubType> AllowedEquipmentSubtypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, int> CharacterActions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FNameArray> ActionsPerLevel;
};

USTRUCT()
struct FEncounter
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<int, FName> Enemies;
};

USTRUCT(BlueprintType)
struct FEnemyInformation : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName EnemyHardcodedName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText EnemyDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExperienceReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GoldReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ABattleCharacterBase* CharacterActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECharacterStatType, float> EnemyStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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