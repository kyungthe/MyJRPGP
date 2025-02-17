// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomStruct.h"
#include "JRPGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYJRPGP_API UJRPGGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void ClearCharactersCollection();
	int32 GetCharactersCollectionLength() const;
	void AddCharacterInformation(FCharacterInformation& CharacterInformation);

	void ClearCurrentParty();
	void ClearInventory();

	void SetTimePlayed(float InTime);

	void SetGold(int32 InGold);

	void AddItemDynamicDataToInventory(FItemDynamicData& ItemDynamicData);

	void ClearInteractedObjects();

	void ClearBattledEnemies();

	void AddBattledEnemyState(FName EnemyName, bool State);
	const bool* GetBattledEnemyState(FName EnemyName) const;

	const FTransform* GetWorldEnemyTransformBeforeBattle(FName EnemyName) const;

	bool IsSpawningAfterBattle() const;

	void SetEncounteredEnemies(const TMap<int, FName>& InEncounteredEnemies);

	void SetWorldTransformBeforeBattle(const FTransform& InWorldTransformBeforeBattle);

	void SetCameraWorldRotationBeforeBattle(const FRotator& InCameraWorldRotationBeforeBattle);

	void SetWorldEnemiesTransformsBeforeBattle(const TMap<FName, FTransform>& InWorldEnemiesTransformsBeforeBattle);

public:
	UPROPERTY()
		TMap<FName, FCharacterInformation> CharactersCollection;

	UPROPERTY()
		TArray<FPartySlot> CurrentParty;

	UPROPERTY()
		TArray<FItemDynamicData> Inventory;

	float TimePlayed;

	int32 Gold;

	UPROPERTY()
		TMap<FName, bool> InteractedObjects;

	UPROPERTY()
		TMap<FName, bool> BattledEnemies;

	UPROPERTY()
		FTransform WorldTransformBeforeBattle;

	UPROPERTY()
		TMap<FName, FTransform> WorldEnemiesTransformsBeforeBattle;

	UPROPERTY()
		bool SpawningAfterBattle;

	UPROPERTY()
		TMap<int, FName> EncounteredEnemies;

	UPROPERTY()
		FRotator CameraWorldRotationBeforeBattle;
};
