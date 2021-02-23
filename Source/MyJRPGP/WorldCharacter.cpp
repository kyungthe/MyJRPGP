// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldCharacter.h"
#include "Interaction.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>

// Sets default values
AWorldCharacter::AWorldCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	if (SpringArmComponent)
	{
		SpringArmComponent->bUsePawnControlRotation = true;
		SpringArmComponent->SetupAttachment(RootComponent);
	}

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	if (CameraComponent)
	{
		CameraComponent->SetupAttachment(SpringArmComponent);
	}

	// 리소스가 없어서 임시로 마네킹을 사용한다.
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

	ActorToInteract = nullptr;
	WorldController = nullptr;
}

AWorldController* AWorldCharacter::GetWorldController()
{
	return WorldController;
}

// Called when the game starts or when spawned
void AWorldCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

AActor* AWorldCharacter::GetNearestActorinInteractionRange()
{
	if (ActorsInInteractionRange.Num() <= 0)
	{
		return nullptr;
	}

	float DistanceToNearestActor = 5000.0f;
	AActor* NearestActor = nullptr;

	for (AActor* Actor : ActorsInInteractionRange)
	{
		float Distance = GetDistanceTo(Actor);
		if (Distance < DistanceToNearestActor)
		{
			DistanceToNearestActor = Distance;
			NearestActor = Actor;
		}
	}

	return NearestActor;
}

// Called every frame
void AWorldCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AActor* NearestActorinInteractionRange = GetNearestActorinInteractionRange();
	if (ActorToInteract != NearestActorinInteractionRange)
	{
		if (ActorToInteract)
		{
			IInteraction* Interaction = Cast<IInteraction>(ActorToInteract);
			if (Interaction)
			{
				Interaction->OnInteractionDisabled();
			}
		}

		if (NearestActorinInteractionRange)
		{
			ActorToInteract = NearestActorinInteractionRange;
			IInteraction* Interaction = Cast<IInteraction>(ActorToInteract);
			if (Interaction)
			{
				Interaction->OnInteractionEnabled();
			}
		}
	}
}

// Called to bind functionality to input
void AWorldCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

