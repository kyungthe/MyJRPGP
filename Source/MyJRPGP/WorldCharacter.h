// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WorldCharacter.generated.h"

class AWorldController;

UCLASS()
class MYJRPGP_API AWorldCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWorldCharacter();

	AWorldController* GetWorldController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AActor* GetNearestActorinInteractionRange();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY()
	class UCameraComponent* CameraComponent;

	UPROPERTY()
	TArray<AActor*> ActorsInInteractionRange;

	UPROPERTY()
	AActor* ActorToInteract;

	UPROPERTY()
	AWorldController* WorldController;
};
