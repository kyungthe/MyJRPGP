// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "JRPGGameInstance.h"
#include "CharacterManager.h"
#include "MainMenuController.h"
#include <Engine/DataTable.h>
#include "CustomStruct.h"

// Sets default values for this component's properties
USaveManager::USaveManager() : CharacterDataTable(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> FindDataTable(TEXT("/Game/MyJRPG/DataTable/CharacterDataTable"));
	if (FindDataTable.Succeeded())
	{
		CharacterDataTable = FindDataTable.Object;
	}
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
		AMainMenuController* MainMenuController = Cast<AMainMenuController>(Owner);
		UCharacterManager* CharacterManager = MainMenuController->GetCharacterManager();
		if (IsValid(CharacterManager))
		{
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

