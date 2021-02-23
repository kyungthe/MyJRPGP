// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WorldController.generated.h"

class UBattleManager;

/**
 * 
 */
UCLASS()
class MYJRPGP_API AWorldController : public APlayerController
{
	GENERATED_BODY()

public:
	UBattleManager* GetBattleManager();

private:
	UBattleManager* BattleManager;
};
