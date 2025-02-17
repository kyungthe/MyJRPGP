﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterManager.h"
#include "CustomStruct.h"
#include "JRPGGameInstance.h"
#include "BattleManager.h"

// Sets default values for this component's properties
UCharacterManager::UCharacterManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxCharactersAmountInCollection = 15;
}


// Called when the game starts
void UCharacterManager::BeginPlay()
{
	Super::BeginPlay();

	JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();	
}

void UCharacterManager::AddNewCharacterToCollection(FCharacterInformation& CharacterInformation)
{
	if (JrpgGameInstance)
	{
		int32 CharacterCollectionLength = JrpgGameInstance->GetCharactersCollectionLength();
		if (CharacterCollectionLength < MaxCharactersAmountInCollection)
		{
			TMap<EItemType, FItemStaticData>& CharacterEquipment = CharacterInformation.CharacterEquipment;
			UDataTable* ItemDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/MyJRPG/DataTable/ItemDataTable"), nullptr, LOAD_None, nullptr);
			for (auto& Pair : CharacterEquipment)
			{
				FItemStaticData& CharacterItemStaticData = Pair.Value;
				if (ItemDataTable)
				{
					FItemStaticData* FindItemStaticData = ItemDataTable->FindRow<FItemStaticData>(CharacterItemStaticData.ItemHardcodedName, "");
					if (FindItemStaticData)
					{
						IncreaseCharacterStats(CharacterInformation, FindItemStaticData->ItemStats);
						CharacterItemStaticData = *FindItemStaticData;
					}
				}
			}

			JrpgGameInstance->AddCharacterInformation(CharacterInformation);
		}
	}
}

void UCharacterManager::IncreaseCharacterStats(FCharacterInformation& CharacterInformation, TMap<ECharacterStatType, float>& ItemStats)
{
	for (auto& Pair : ItemStats)
	{
		ECharacterStatType StatType = Pair.Key;
		float StatValue = Pair.Value;
		CharacterInformation.CharacterStats[StatType] += StatValue;

		if (StatType == ECharacterStatType::HP)
		{
			AActor* Owner = GetOwner();
			UActorComponent* ActorComponent = Owner->GetComponentByClass(UCharacterManager::StaticClass());
			UBattleManager* CharacterManager = Cast<UBattleManager>(ActorComponent);

			float CurrentHP = CharacterManager->GetPlayerCharacterCurrentHP(CharacterInformation.CharacterHardcodedName);
			CurrentHP += StatValue;
			CharacterManager->SetPlayerCharacterCurrentHP(CharacterInformation.CharacterHardcodedName, CurrentHP);
		}
		else if (StatType == ECharacterStatType::MP)
		{
			AActor* Owner = GetOwner();
			UActorComponent* ActorComponent = Owner->GetComponentByClass(UCharacterManager::StaticClass());
			UBattleManager* CharacterManager = Cast<UBattleManager>(ActorComponent);

			float CurrentMP = CharacterManager->GetPlayerCharacterCurrentMP(CharacterInformation.CharacterHardcodedName);
			CurrentMP += StatValue;
			CharacterManager->SetPlayerCharacterCurrentMP(CharacterInformation.CharacterHardcodedName, CurrentMP);
		}
	}
}


// Called every frame
void UCharacterManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

