// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/LocalPlayer.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraS"));
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleS"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmS"));
	Capsule->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(Capsule);
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Custom Input Axis Bindings
	InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);

	InputComponent->BindAxis("HoriRot", this, &AMainPlayer::HoriRot);
	InputComponent->BindAxis("VertRot", this, &AMainPlayer::VertRot);

	// Custom Active Bidnig
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMainPlayer::Jump);

}

void AMainPlayer::MoveRight(float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AMainPlayer::MoveForward(float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMainPlayer::HoriRot(float Value)
{
	if (Value)
	{
		AddActorLocalRotation(FRotator(0, Value, 0));
	}
}

void AMainPlayer::VertRot(float Value)
{
	if (Value)
	{
		float temp = Camera->GetRelativeRotation().Pitch + Value;

		if (temp < 65 && temp > -65)
		{
			Camera->AddLocalRotation(FRotator(Value, 0, 0));
		}
	}
}

void AMainPlayer::Jump()
{

}

