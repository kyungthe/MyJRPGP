// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interaction.h"
#include "NPCBase.generated.h"

UCLASS()
class MYJRPGP_API ANPCBase : public ACharacter, public IInteraction
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCBase();

public:

	virtual void OnObjectInteractionStateLoaded(bool InteractionState) override;

	virtual void OnEnemyBattleStateLoaded(bool BattleState) override;

	virtual void OnInteractionEnabled() override;

	virtual void OnInteractionDisabled() override;

	virtual void OnInteractionRequested(class WorldCharacter* WorldCharacter) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* InteractionRange;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* InteractionSign;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* WidgetComponent;

	float InteractionRadius;
};
