// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBase.h"
#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/WidgetComponent.h>

// Sets default values
ANPCBase::ANPCBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionRange = CreateDefaultSubobject<USphereComponent>("InteractionRange");
	if (InteractionRange)
	{
		InteractionRadius = 200.0f;
		InteractionRange->SetSphereRadius(InteractionRadius);
		InteractionRange->SetupAttachment(RootComponent);
	}

	USkeletalMeshComponent* SkeletalMeshComponent = GetMesh();
	if (SkeletalMeshComponent)
	{
		// 리소스가 없어서 임시로 마네킹을 사용한다.
		ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin"));
		if (SkeletalMesh.Succeeded())
		{
			SkeletalMeshComponent->SetSkeletalMesh(SkeletalMesh.Object);
			SkeletalMeshComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
		}
	}

	InteractionSign = CreateDefaultSubobject<UStaticMeshComponent>("InteractionSign");
	if (InteractionSign)
	{
		// 리소스가 없어서 아직 메시를 붙이진 않는다.
		//ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
		InteractionSign->SetupAttachment(RootComponent);
	}

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("WidgetComponent");
	if (WidgetComponent)
	{
		ConstructorHelpers::FClassFinder<UUserWidget> InteractInfo3DWidgetAsset(TEXT("/Game/MyJRPG/Widget/InteractInfo3D"));
		if (InteractInfo3DWidgetAsset.Succeeded())
		{
			WidgetComponent->SetWidgetClass(InteractInfo3DWidgetAsset.Class);
		}
		WidgetComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 130.0f), FRotator(0.0f, 0.0f, 0.0f));
		WidgetComponent->SetDrawSize(FVector2D(500.0f, 500.0f));
		WidgetComponent->SetPivot(FVector2D(0.5f, 0.5f));
		WidgetComponent->SetDrawAtDesiredSize(true);
		WidgetComponent->SetupAttachment(RootComponent);
	}
}

void ANPCBase::OnObjectInteractionStateLoaded(bool InteractionState)
{

}

void ANPCBase::OnEnemyBattleStateLoaded(bool BattleState)
{

}

void ANPCBase::OnInteractionEnabled()
{
	WidgetComponent->SetHiddenInGame(false);
}

void ANPCBase::OnInteractionDisabled()
{
	WidgetComponent->SetHiddenInGame(true);
}

void ANPCBase::OnInteractionRequested(class WorldCharacter* WorldCharacter)
{

}

// Called when the game starts or when spawned
void ANPCBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

