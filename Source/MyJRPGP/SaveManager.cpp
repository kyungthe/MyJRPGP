// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include <GameFramework/Actor.h>

// Sets default values for this component's properties
USaveManager::USaveManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USaveManager::BeginPlay()
{
	Super::BeginPlay();

	//GetGameInstance();
}


// Called every frame
void USaveManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

