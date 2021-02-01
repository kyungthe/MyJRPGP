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
	void AddCharacterInformation(struct FCharacterInformation&);

	void ClearCurrentParty();
	void ClearInventory();

	void SetTimePlayed(float InTime);

public:
	UPROPERTY()
		TMap<FName, FCharacterInformation> CharactersCollection;

	UPROPERTY()
		TArray<FPartySlot> CurrentParty;

	UPROPERTY()
		TArray<FItemDynamicData> Inventory;

	float TimePlayed;
};
