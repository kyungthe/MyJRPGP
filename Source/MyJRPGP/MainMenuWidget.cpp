// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "SaveManager.h"

void UMainMenuWidget::SetSaveManager(USaveManager* InSaveManager)
{
	if (InSaveManager)
		SaveManager = InSaveManager;
}

USaveManager* UMainMenuWidget::GetSaveManager() const
{
	return SaveManager;
}