// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuController.h"
#include <Blueprint/UserWidget.h>

AMainMenuController::AMainMenuController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> FindWidget(TEXT("/Game/MyJRPG/Widget/MainMenu"));
	MainMenuWidgetClass = FindWidget.Class;
}

void AMainMenuController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameAndUI());
	UUserWidget* MainMenuWidget = CreateWidget(GetWorld(), MainMenuWidgetClass);
	if (MainMenuWidget)
		MainMenuWidget->AddToViewport();
}
