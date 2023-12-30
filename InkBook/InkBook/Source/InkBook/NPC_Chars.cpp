// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Chars.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ANPC_Chars::ANPC_Chars()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharPanel"));
	CharPanel->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ANPC_Chars::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC_Chars::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LootAtPlayer();

}

// Called to bind functionality to input
void ANPC_Chars::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPC_Chars::LootAtPlayer()
{
	PlayerPostion = GetWorld()->GetFirstPlayerController()->GetPawn()->GetTargetLocation();
	CharPanel->SetRelativeRotation(UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), PlayerPostion));
	CharPanel->AddRelativeRotation(FRotator(0, -90, -270));
	CharPanel->SetRelativeRotation(FRotator(0, CharPanel->GetRelativeRotation().Yaw, CharPanel->GetRelativeRotation().Roll));
}

