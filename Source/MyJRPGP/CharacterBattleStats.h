// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomEnum.h"
#include "CharacterBattleStats.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYJRPGP_API UCharacterBattleStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterBattleStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY()
	FName CharacterHardcodedName;

	UPROPERTY()
	FText CharacterDisplayName;

	UPROPERTY()
	TMap<ECharacterStatType, float> CharacterStats;

	float CurrentHP;

	float CurrentMP;
};
