// Fill out your copyright notice in the Description page of Project Settings.


#include "JRPGGameInstance.h"

void UJRPGGameInstance::ClearCharactersCollection()
{
	CharactersCollection.Reset();
}

int32 UJRPGGameInstance::GetCharactersCollectionLength() const
{
	return CharactersCollection.Num();
}

void UJRPGGameInstance::AddCharacterInformation(FCharacterInformation CharacterInformation)
{
	FName CharacterName = CharacterInformation.CharacterHardcodedName;
	
	CharactersCollection.Add(CharacterName, CharacterInformation);
}

void UJRPGGameInstance::ClearCurrentParty()
{
	CurrentParty.Reset();
}

void UJRPGGameInstance::ClearInventory()
{
	Inventory.Reset();
}

void UJRPGGameInstance::SetTimePlayed(float InTime)
{
	TimePlayed = InTime;
}
