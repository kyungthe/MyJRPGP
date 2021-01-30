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

	class UCharacterManager* GetCharacterManager() const;

public:
	UPROPERTY()
	class TSubclassOf<class UMainMenuWidget> MainMenuWidgetClass;

	UPROPERTY()
	class USaveManager* SaveManager;

	UPROPERTY()
	class UCharacterManager* CharacterManager;
};
