// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WorldEnemyBase.generated.h"

UCLASS()
class MYJRPGP_API AWorldEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWorldEnemyBase();

	void SetEnemyBattleState(bool State);
	const bool* GetEnemyBattleState() const;

	void OnEnemyBattleStateLoaded(bool BattleState);

	void OnActivationRangeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor
		, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnEncounterRangeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor
		, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	const FName GetEnemyGlobalID() const;

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
	class USphereComponent* ActivationRange;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* EncounterRange;

	float ActivationRadius;

	float EncounterRadius;

	FName EnemyGlobalID;

	UPROPERTY()
	class AWorldCharacter* PlayerCharacter;

	TArray<FName> PossibleEncounters;

	TArray<FName> PossibleBattleMaps;
};
