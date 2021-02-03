// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BattleManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYJRPGP_API UBattleManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBattleManager();

	void SetPlayerCharacterCurrentHP(FName CharacterName, float HP);
	float GetPlayerCharacterCurrentHP(FName CharacterName) const;

	void SetPlayerCharacterCurrentMP(FName CharacterName, float MP);
	float GetPlayerCharacterCurrentMP(FName CharacterName) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY()
	TArray<class ABattleCharacterBase*> PlayerCharacters;
};
