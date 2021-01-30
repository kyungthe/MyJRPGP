// Fill out your copyright notice in the Description page of Project Settings.


#include "JRPGGameInstance.h"

void UJRPGGameInstance::ClearCharactersCollection()
{
	CharactersCollection.Reset();
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
