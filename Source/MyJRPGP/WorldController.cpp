// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldController.h"
#include "BattleManager.h"

UBattleManager* AWorldController::GetBattleManager()
{
	return BattleManager;
}
