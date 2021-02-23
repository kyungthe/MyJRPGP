// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldEnemyBase.h"
#include <Components/SphereComponent.h>
#include <Components/CapsuleComponent.h>
#include "WorldCharacter.h"
#include "WorldController.h"
#include "BattleManager.h"
#include "JRPGGameInstance.h"

// Sets default values
AWorldEnemyBase::AWorldEnemyBase() : EnemyGlobalID("None")
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActivationRange = CreateDefaultSubobject<USphereComponent>("ActivationRange");
	if (ActivationRange)
	{
		ActivationRadius = 500.0f;
		ActivationRange->SetSphereRadius(ActivationRadius);
		ActivationRange->SetupAttachment(RootComponent);

		FScriptDelegate ScriptDelegate;
		ScriptDelegate.BindUFunction(this, "OnActivationRangeBeginOverlap");
		ActivationRange->OnComponentBeginOverlap.Add(ScriptDelegate);
	}

	EncounterRange = CreateDefaultSubobject<USphereComponent>("EncounterRange");
	if (EncounterRange)
	{
		EncounterRadius = 100.0f;
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

void AWorldEnemyBase::SetEnemyBattleState(bool State)
{
	UJRPGGameInstance* JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();
	if (JrpgGameInstance)
	{
		JrpgGameInstance->AddBattledEnemyState(EnemyGlobalID, State);
	}
}

const bool* AWorldEnemyBase::GetEnemyBattleState() const
{
	UJRPGGameInstance* JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();
	if (JrpgGameInstance)
	{
		return JrpgGameInstance->GetBattledEnemyState(EnemyGlobalID);
	}

	return nullptr;
}

// Called when the game starts or when spawned
void AWorldEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	UJRPGGameInstance* JrpgGameInstance = GetWorld()->GetGameInstance<UJRPGGameInstance>();
	if (JrpgGameInstance)
	{
		const FTransform* Transform = JrpgGameInstance->GetWorldEnemyTransformBeforeBattle(EnemyGlobalID);
		if (Transform)
		{
			bool IsSpawningAfterBattle = JrpgGameInstance->IsSpawningAfterBattle();
			if (IsSpawningAfterBattle)
			{
				SetActorTransform(*Transform);
			}
		}

		const bool* BattleState = GetEnemyBattleState();
		if (BattleState)
		{
			OnEnemyBattleStateLoaded(*BattleState);
		}
	}
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

void AWorldEnemyBase::OnEnemyBattleStateLoaded(bool BattleState)
{
	if (BattleState)
	{
		Destroy();
	}
	else
	{
		EncounterRange->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void AWorldEnemyBase::OnActivationRangeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWorldCharacter* WorldCharacter = Cast<AWorldCharacter>(OtherActor);
	if (WorldCharacter)
	{
		PlayerCharacter = WorldCharacter;
	}
}

void AWorldEnemyBase::OnEncounterRangeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWorldCharacter* WorldCharacter = Cast<AWorldCharacter>(OtherActor);
	if (WorldCharacter)
	{
		SetEnemyBattleState(true);

		int Index = FMath::RandRange(0, PossibleEncounters.Num() - 1);
		FName EncounterName = PossibleEncounters[Index];

		Index = FMath::RandRange(0, PossibleBattleMaps.Num() - 1);
		FName BattleMapName = PossibleBattleMaps[Index];

		AWorldController* WorldController = WorldCharacter->GetWorldController();
		if (!WorldController)
			return;

		UBattleManager* BattleManager = WorldController->GetBattleManager();
		if (!BattleManager)
			return;

		BattleManager->EncounterEnemies(EncounterName, BattleMapName);
	}
}

const FName AWorldEnemyBase::GetEnemyGlobalID() const
{
	return EnemyGlobalID;
}
