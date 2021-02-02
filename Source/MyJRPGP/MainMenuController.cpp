// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuController.h"
#include <Blueprint/UserWidget.h>
#include "SaveManager.h"
#include "CharacterManager.h"
#include "MainMenuWidget.h"

AMainMenuController::AMainMenuController() : 
	MainMenuWidgetClass(nullptr), SaveManager(nullptr), CharacterManager(nullptr)
{
	static ConstructorHelpers::FClassFinder<UMainMenuWidget> FindWidget(TEXT("/Game/MyJRPG/Widget/MainMenuBP"));
	if(FindWidget.Succeeded())
		MainMenuWidgetClass = FindWidget.Class;

	SaveManager = CreateDefaultSubobject<USaveManager>("SaveManager");
	CharacterManager = CreateDefaultSubobject<UCharacterManager>("CharacterManager");
}

void AMainMenuController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameAndUI());

	if (MainMenuWidgetClass)
	{
		UUserWidget* CreatedWidget = CreateWidget(GetWorld(), MainMenuWidgetClass);
		UMainMenuWidget* MainMenuWidget = Cast<UMainMenuWidget>(CreatedWidget);
		if (MainMenuWidget)
		{
			MainMenuWidget->AddToViewport();

			if (SaveManager)
				MainMenuWidget->SetSaveManager(SaveManager);
		}
	}
}