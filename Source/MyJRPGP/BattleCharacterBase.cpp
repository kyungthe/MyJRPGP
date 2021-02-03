// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleCharacterBase.h"
#include "CharacterBattleStats.h"

// Sets default values
ABattleCharacterBase::ABattleCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterStats = CreateDefaultSubobject<UCharacterBattleStats>("CharacterBattleStats");
}

void ABattleCharacterBase::SetCurrentHP(float HP)
{
	if (HP < 0.0f)
		HP = 0.0f;

	CharacterStats->CurrentHP = HP;
}

float ABattleCharacterBase::GetCurrentHP() const
{
	return CharacterStats->CurrentHP;
}

void ABattleCharacterBase::SetCurrentMP(float MP)
{
	if (MP < 0.0f)
		MP = 0.0f;

	CharacterStats->CurrentMP = MP;
}

float ABattleCharacterBase::GetCurrentMP() const
{
	return CharacterStats->CurrentMP;
}

const FName ABattleCharacterBase::GetCharacterHardcodedName() const
{
	return CharacterStats->CharacterHardcodedName;
}

// Called when the game starts or when spawned
void ABattleCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattleCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

