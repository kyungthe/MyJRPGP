// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapSpawnPoint.generated.h"

UCLASS()
class MYJRPGP_API AMapSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapSpawnPoint();

	const FTransform& GetSpawnTransform() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	class UCapsuleComponent* CapsuleComponent;
	
	class UTextRenderComponent* TextRenderComponent;

	class UArrowComponent* ArrowComponent;
};
