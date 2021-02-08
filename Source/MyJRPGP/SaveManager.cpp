// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "JRPGGameInstance.h"
#include "CharacterManager.h"
#include "MainMenuController.h"
#include <Engine/DataTable.h>
#include "CustomStruct.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
USaveManager::USaveManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void USaveManager::StartNewGame()
{
	UJRPGGameInstance* JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();
	if (JrpgGameInstance)
	{
		JrpgGameInstance->ClearCharactersCollection();
		JrpgGameInstance->ClearCurrentParty();
		JrpgGameInstance->ClearInventory();

		JrpgGameInstance->SetTimePlayed(0.0f);

		AActor* Owner = GetOwner();
		UActorComponent* ActorComponent = Owner->GetComponentByClass(UCharacterManager::StaticClass());
		UCharacterManager* CharacterManager = Cast<UCharacterManager>(ActorComponent);
		if (IsValid(CharacterManager))
		{
			UDataTable* CharacterDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/MyJRPG/DataTable/CharacterDataTable"), nullptr, LOAD_None, nullptr);
			if (CharacterDataTable)
			{
				TArray<FName> CharacterNames = { "Mark" };
				for (FName CharacterName : CharacterNames)
				{
					FCharacterInformation* CharacterInfomation = CharacterDataTable->FindRow<FCharacterInformation>(CharacterName, "");
					if (CharacterInfomation)
					{
						CharacterManager->AddNewCharacterToCollection(*CharacterInfomation);
					}
				}
			}
		}

		JrpgGameInstance->SetGold(50);

		TMap<FName, int32> DefaultItems;
		DefaultItems.Add("Potion_HP_01",		5);
		DefaultItems.Add("Potion_MP_01",		3);
		DefaultItems.Add("Potion_Revive_01",	4);
		DefaultItems.Add("Potion_HP_02",		1);
		DefaultItems.Add("Dagger_01",			1);

		for (auto& Pair : DefaultItems)
		{
			FName ItemName = Pair.Key;
			int32 Amount = Pair.Value;
			UDataTable* ItemDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/MyJRPG/DataTable/ItemDataTable"), nullptr, LOAD_None, nullptr);
			FItemDynamicData ItemDynamicData;
			FItemStaticData* pItemStaticData = ItemDataTable->FindRow<FItemStaticData>(ItemName, "");
			ItemDynamicData.ItemStaticData = *pItemStaticData;
			ItemDynamicData.StacksAmount = Amount;

			JrpgGameInstance->AddItemDynamicDataToInventory(ItemDynamicData);
		}

		JrpgGameInstance->ClearInteractedObjects();
		JrpgGameInstance->ClearBattledEnemies();

		//UGameplayStatics::OpenLevel();
	}
}

// Called when the game starts
void USaveManager::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USaveManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

