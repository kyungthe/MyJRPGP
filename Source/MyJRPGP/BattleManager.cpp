// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleManager.h"
#include "BattleCharacterBase.h"

// Sets default values for this component's properties
UBattleManager::UBattleManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UBattleManager::SetPlayerCharacterCurrentHP(FName CharacterName, float HP)
{
	for (ABattleCharacterBase* Character : PlayerCharacters)
	{
		if (Character->GetCharacterHardcodedName() == CharacterName)
		{
			return Character->SetCurrentHP(HP);
		}
	}
}

float UBattleManager::GetPlayerCharacterCurrentHP(FName CharacterName) const
{
	for (ABattleCharacterBase* Character : PlayerCharacters)
	{
		if (Character->GetCharacterHardcodedName() == CharacterName)
		{
			return Character->GetCurrentHP();
		}
	}

	return -1.0f;
}

void UBattleManager::SetPlayerCharacterCurrentMP(FName CharacterName, float MP)
{
	for (ABattleCharacterBase* Character : PlayerCharacters)
	{
		if (Character->GetCharacterHardcodedName() == CharacterName)
		{
			return Character->SetCurrentMP(MP);
		}
	}
}

float UBattleManager::GetPlayerCharacterCurrentMP(FName CharacterName) const
{
	for (ABattleCharacterBase* Character : PlayerCharacters)
	{
		if (Character->GetCharacterHardcodedName() == CharacterName)
		{
			return Character->GetCurrentMP();
		}
	}

	return -1.0f;
}

// Called when the game starts
void UBattleManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBattleManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

