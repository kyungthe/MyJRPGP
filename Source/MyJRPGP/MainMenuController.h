// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuController.generated.h"

/**
 * 
 */
UCLASS()
class MYJRPGP_API AMainMenuController : public APlayerController
{
	GENERATED_BODY()

public:
	AMainMenuController();

	void BeginPlay() override;

public:
	class TSubclassOf<UUserWidget> MainMenuWidgetClass;
};
