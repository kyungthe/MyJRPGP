// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SaveManager.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYJRPGP_API USaveManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	USaveManager();

	UFUNCTION(BlueprintCallable)
	void StartNewGame();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	class UDataTable* CharacterDataTable;
};
