// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldEnemyBase.h"
#include <Components/SphereComponent.h>
#include <Components/CapsuleComponent.h>

// Sets default values
AWorldEnemyBase::AWorldEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActivationRange = CreateDefaultSubobject<USphereComponent>("ActivationRange");
	if (ActivationRange)
	{
		ActivationRadius = 500;
		ActivationRange->SetSphereRadius(ActivationRadius);
		ActivationRange->SetupAttachment(RootComponent);
	}

	EncounterRange = CreateDefaultSubobject<USphereComponent>("EncounterRange");
	if (EncounterRange)
	{
		EncounterRadius = 100;
		EncounterRange->SetSphereRadius(EncounterRadius);
		EncounterRange->SetupAttachment(RootComponent);
	}

	USkeletalMeshComponent* SkeletalMeshComponent = GetMesh();
	if (SkeletalMeshComponent)
	{
		ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin"));
		if (SkeletalMesh.Succeeded())
		{
			SkeletalMeshComponent->SetSkeletalMesh(SkeletalMesh.Object);
			SkeletalMeshComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
		}
	}
}

// Called when the game starts or when spawned
void AWorldEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWorldEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

