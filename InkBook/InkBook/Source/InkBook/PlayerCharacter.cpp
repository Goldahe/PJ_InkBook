// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Hands = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hands"));
	Hands->SetupAttachment(Camera);

	LLWall = CreateDefaultSubobject<USphereComponent>(TEXT("LLWall"));
	LLWall->SetupAttachment(Camera);

	RLWall = CreateDefaultSubobject<USphereComponent>(TEXT("RLWall"));
	RLWall->SetupAttachment(Camera);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay() 
{
	Super::BeginPlay();

	HandsPosition = Hands->GetRelativeLocation();
	HandsPositionL = FVector(HandsPosition.X, HandsPosition.Y - 5.f, HandsPosition.Z - 2.f);
	HandsPositionR = FVector(HandsPosition.X, HandsPosition.Y + 5.f, HandsPosition.Z - 2.f);
	HandsPositionJump = FVector(HandsPosition.X, HandsPosition.Y, HandsPosition.Z - 5.f);

	LLWall->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OverlapBegin);
	LLWall->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::OverlapEnd);

	RLWall->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OverlapBegin);
	RLWall->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::OverlapEnd);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	dTime = DeltaTime;

	// FOV change for Sprinting --------------------------------------------------------------
	CurrentFOV = Camera->FieldOfView;
	if (isSprinting && ForwardMove > 0.f && CharM->Velocity.Length() > MaxSpeed)
		Camera->FieldOfView = FMath::Lerp(CurrentFOV, FMath::Lerp(NormalFOV, SprintlFOV, ForwardMove), 5.f * DeltaTime);
	else
		Camera->FieldOfView = FMath::Lerp(CurrentFOV, NormalFOV, 5.f * DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("MoveSpeed: %f, CurrentFov: %f, Speed: %d"), ForwardMove, CurrentFOV, CharM->Velocity.Length());

	PlayerLocation = this->GetActorLocation();

	HandMovement();
	WallRun();

	//FootStepTick = false;

	if (JumpTriggered)
		JumpTriggered=!JumpTriggered;

}

// Called to bind functionality to input 
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) 
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Custom Input Axis Bindings
	InputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	InputComponent->BindAxis("HoriRot", this, &APlayerCharacter::HoriRot); 
	InputComponent->BindAxis("VertRot", this, &APlayerCharacter::VertRot);

	// Custom Active Bidnig
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::JumpAction);
	InputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::SprintStart);
	InputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::SprintEnd);
}

void APlayerCharacter::SprintStart()
{
	CharM->MaxWalkSpeed = MaxSpeed * SpirntMulti;
	isSprinting = true;
}

void APlayerCharacter::SprintEnd()
{
	CharM->MaxWalkSpeed = MaxSpeed;
	isSprinting = false;
}

void APlayerCharacter::MoveRight(float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void APlayerCharacter::MoveForward(float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
	ForwardMove = Value;

}

void APlayerCharacter::HoriRot(float Value)
{
	if (Value)
	{
		AddActorLocalRotation(FRotator(0, Value, 0));
	}
}

void APlayerCharacter::VertRot(float Value)
{
	if (Value)
	{
		float temp = Camera->GetRelativeRotation().Pitch + Value;
		
		if (temp < 65 && temp > -65)
		{
			Camera->AddLocalRotation(FRotator(Value,0,0));
		}
	}
}

void APlayerCharacter::JumpAction()
{
	Jump();
	JumpTriggered = true;
}

void APlayerCharacter::HandMovement()
{
	if ((Hands->GetRelativeLocation().Y >= HandsPosition.Y - 0.1f && Hands->GetRelativeLocation().Y <= HandsPosition.Y + 0.1f) && ForwardMove > 0.f)
	{		
		HandSwaveStage = SWAY_L_R;
		PassTime = 0.f;
	}

	if (Hands->GetRelativeLocation().Y <= HandsPositionL.Y)
	{
		HandSwaveStage = SWAY_R;
		HandSwave = !HandSwave;
		PassTime = 0.f;
		FootStepTick = true;
		UE_LOG(LogTemp, Warning, TEXT("L"));
	}

	if (Hands->GetRelativeLocation().Y >= HandsPositionR.Y)
	{
		HandSwaveStage = SWAY_L;
		HandSwave = !HandSwave;
		PassTime = 0.f;
		FootStepTick = true;
		UE_LOG(LogTemp, Warning, TEXT("R"));
	}

	if (ForwardMove >= 0.f  && ForwardMove < 0.1f)
	{
		HandSwaveStage = SWAY_NA;
		PassTime = 0.f;
	}

	if (CharM->IsFalling())
	{
		HandSwaveStage = SWAY_Jump;
		PassTime = 0.f;
	}
	
	if (HandSwaveStage == SWAY_L_R)
		if (HandSwave)
			Hands->SetRelativeLocation(FMath::Lerp(HandsPosition, HandsPositionL, HandMoveCalc()));
		else
			Hands->SetRelativeLocation(FMath::Lerp(HandsPosition, HandsPositionR, HandMoveCalc()));

	if (HandSwaveStage == SWAY_R)
		Hands->SetRelativeLocation(FMath::Lerp(HandsPositionL, HandsPosition, HandMoveCalc()));

	if (HandSwaveStage == SWAY_L)
		Hands->SetRelativeLocation(FMath::Lerp(HandsPositionR, HandsPosition, HandMoveCalc()));

	if (HandSwaveStage == SWAY_NA)
		Hands->SetRelativeLocation(FMath::Lerp(Hands->GetRelativeLocation(), HandsPosition, HandMoveCalc()));
	if (HandSwaveStage == SWAY_Jump)
		Hands->SetRelativeLocation(FMath::Lerp(Hands->GetRelativeLocation(), HandsPositionJump, HandMoveCalc()));
}

float APlayerCharacter::HandMoveCalc() 
{
	PassTime = PassTime + dTime * HandSwaySpeed * (CharM->MaxWalkSpeed / MaxSpeed);
	return PassTime;
}

void APlayerCharacter::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && CharM->IsFalling() && !LeftLegCollision && OverlappedComponent == LLWall && ForwardMove > 0.f && !LeftLegTag)
	{
		LeftLegCollision = true;
		LeftLegTag = true;
		CharM->GravityScale = 0;
		//if (CharM->Velocity.Z <= 0.f)
			CharM->Velocity.Z = 0;
		this->JumpMaxCount = 1;
	}
	if (OtherActor && OtherActor != this && CharM->IsFalling() && !RightLegCollision && OverlappedComponent == RLWall&& ForwardMove > 0.f && !RightLegTag)
	{
		RightLegCollision = true;
		RightLegTag = true;
		CharM->GravityScale = 0;
		//if (CharM->Velocity.Z <= 0.f)
			CharM->Velocity.Z = 0;
		this->JumpMaxCount = 1;
	}
}

void APlayerCharacter::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (LeftLegCollision && OtherActor && OtherActor != this)
	{
		this->JumpMaxCount = 2;
		this->JumpCurrentCount = 1;
		LeftLegCollision = false;
		RightLegTag = false;
	}
	if (RightLegCollision && OtherActor && OtherActor != this)
	{
		this->JumpMaxCount = 2;
		this->JumpCurrentCount = 1;
		RightLegCollision = false;
		LeftLegTag = false;
	}
}

void APlayerCharacter::WallRun()
{
	if (isSprinting && ForwardMove > 0.f && (LeftLegCollision || RightLegCollision))
	{
		CharM->GravityScale = FMath::Lerp(CharM->GravityScale, 1.f, WallRunDelta * dTime);
		if (JumpTriggered)
		{
			if (LeftLegCollision)
			{
				CharM->AddImpulse(Camera->GetRightVector() * 50000);
			}
			if (RightLegCollision)
			{
				CharM->AddImpulse(Camera->GetRightVector() * -50000);
			}
			CharM->AddImpulse(FVector(0.f,0.f,1.f) * 50000);
			UE_LOG(LogTemp, Warning, TEXT("JUMP"));
		}
		UE_LOG(LogTemp, Warning, TEXT("Runing on the wall"));
	}
	else
		CharM->GravityScale = 1.f;

	if (!CharM->IsFalling())
	{
		LeftLegTag = false;
		RightLegTag = false;
	}
}