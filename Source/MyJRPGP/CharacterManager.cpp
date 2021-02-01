// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterManager.h"
#include "CustomStruct.h"
#include "JRPGGameInstance.h"

// Sets default values for this component's properties
UCharacterManager::UCharacterManager() : ItemDataTable(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxCharactersAmountInCollection = 15;

	static ConstructorHelpers::FObjectFinder<UDataTable> FindDataTable(TEXT("/Game/MyJRPG/DataTable/ItemDataTable"));
	if (FindDataTable.Succeeded())
	{
		ItemDataTable = FindDataTable.Object;
	}
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
			for (auto& Pair : CharacterEquipment)
			{
				FItemStaticData& ItemStaticData = Pair.Value;
				if (ItemDataTable)
				{
					FItemStaticData* FindItemStaticData = ItemDataTable->FindRow<FItemStaticData>(ItemStaticData.ItemHardcodedName, "");
					//IncreaseCharacterStats(CharacterInformation.CharacterHardcodedName, FindItemStaticData->ItemStats);
					ItemStaticData = *FindItemStaticData;
				}
			}

			JrpgGameInstance->AddCharacterInformation(CharacterInformation);
		}
	}
}


// Called every frame
void UCharacterManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

