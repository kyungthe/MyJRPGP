// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleManager.h"
#include "BattleCharacterBase.h"
#include "CustomStruct.h"
#include "JRPGGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "WorldEnemyBase.h"

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

void UBattleManager::EncounterEnemies(FName EncounterName, FName BattleMapName)
{
	UDataTable* EncountersTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/MyJRPG/DataTable/Encounters"), nullptr, LOAD_None, nullptr);
	if (EncountersTable)
	{
		FEncounter* Encounter = EncountersTable->FindRow<FEncounter>(EncounterName, "");
		if (Encounter)
		{
			OpenMapBattleMap(BattleMapName, Encounter->Enemies);
		}
	}
}

void UBattleManager::OpenMapBattleMap(FName BattleMapName, TMap<int32, FName>& EncounteredEnemies)
{
	UJRPGGameInstance* JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();
	if (!JrpgGameInstance)
		return;

	JrpgGameInstance->SetEncounteredEnemies(EncounteredEnemies);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!PlayerPawn)
		return;

	const FTransform& PlayerPawnTransform = PlayerPawn->GetActorTransform();
	JrpgGameInstance->SetWorldTransformBeforeBattle(PlayerPawnTransform);

	const FRotator& PlayerPawnRotation = PlayerPawn->GetControlRotation();
	JrpgGameInstance->SetCameraWorldRotationBeforeBattle(PlayerPawnRotation);

	TMap<FName, FTransform> EnemiesTransforms = GetWorldEnemiesTransforms();
	JrpgGameInstance->SetWorldEnemiesTransformsBeforeBattle(EnemiesTransforms);

	UGameplayStatics::OpenLevel(GetWorld(), BattleMapName);
}

TMap<FName, FTransform> UBattleManager::GetWorldEnemiesTransforms()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorldEnemyBase::StaticClass(), Actors);

	TMap<FName, FTransform> EnemiesTransforms;
	for (AActor* Actor : Actors)
	{
		AWorldEnemyBase* WorldEnemy = Cast<AWorldEnemyBase>(Actor);
		if (WorldEnemy)
		{
			const FName EnemyName = WorldEnemy->GetEnemyGlobalID();
			const FTransform& EnemyTransform = WorldEnemy->GetActorTransform();
			EnemiesTransforms.Add(EnemyName, EnemyTransform);
		}
	}

	return EnemiesTransforms;
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

