// Fill out your copyright notice in the Description page of Project Settings.


#include "MapSpawnPoint.h"
#include <Components/CapsuleComponent.h>
#include <Components/ArrowComponent.h>
#include <Components/TextRenderComponent.h>
#include <Components/SceneComponent.h>

// Sets default values
AMapSpawnPoint::AMapSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	if (CapsuleComponent)
	{
		CapsuleComponent->InitCapsuleSize(25.0f, 90.0f);
		CapsuleComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
		CapsuleComponent->SetupAttachment(RootComponent);
	}

	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComponent");
	if (TextRenderComponent)
	{
		TextRenderComponent->Text = FText::FromString("Spawn Point");
		TextRenderComponent->TextRenderColor = FColor(0, 255, 0);
		TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));
		TextRenderComponent->SetupAttachment(CapsuleComponent);
	}

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(0, 255, 0);
		ArrowComponent->SetupAttachment(CapsuleComponent);
	}
}

const FTransform& AMapSpawnPoint::GetSpawnTransform() const
{
	return GetTransform();
}

// Called when the game starts or when spawned
void AMapSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

