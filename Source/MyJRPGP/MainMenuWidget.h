// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYJRPGP_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetSaveManager(class USaveManager* InSaveManager);

	UFUNCTION(BlueprintCallable)
	class USaveManager* GetSaveManager() const;
	
public:
	class USaveManager* SaveManager;
};
