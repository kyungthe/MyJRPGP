// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterManager.h"
#include "CustomStruct.h"
#include "JRPGGameInstance.h"

// Sets default values for this component's properties
UCharacterManager::UCharacterManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterManager::BeginPlay()
{
	Super::BeginPlay();

	JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();	
}

void UCharacterManager::AddNewCharacterToCollection(FCharacterInformation& CharacterInformation)
{

}


// Called every frame
void UCharacterManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

