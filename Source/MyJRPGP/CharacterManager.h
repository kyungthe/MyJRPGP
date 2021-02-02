// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterManager.generated.h"

enum class ECharacterStatType : uint8;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYJRPGP_API UCharacterManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCharacterManager();

	void AddNewCharacterToCollection(struct FCharacterInformation& CharacterInformation);

	void IncreaseCharacterStats(struct FCharacterInformation&, TMap<ECharacterStatType, float>& ItemStats);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY()
	class UJRPGGameInstance* JrpgGameInstance;

	int32 MaxCharactersAmountInCollection;

	class UDataTable* ItemDataTable;
};
