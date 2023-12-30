// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"

enum HandSway
{
	SWAY_L_R = 1,
	SWAY_L = 2,
	SWAY_R = 3,
	SWAY_NA = 4,
	SWAY_Jump = 5
};

UCLASS()
class INKBOOK_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector PlayerLocation;

	float SpirntMulti = 2.0f;
	float NormalFOV = 90.f;
	float SprintlFOV = 100.f;
	float MaxSpeed = 600.f;

	UPROPERTY(BlueprintReadWrite, Category = "FootStepTick")
	bool FootStepTick = false;

	UPROPERTY(EditAnywhere, Category = "HandSwaySpeed")
	float HandSwaySpeed = 3.f;
	UPROPERTY(EditAnywhere, Category = "WallRunDelta")
	float WallRunDelta = 0.5f;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void HoriRot(float Value);
	void VertRot(float Value);
	void JumpAction();
	void SprintStart();
	void SprintEnd();
	void HandMovement();
	void WallRun();
	float HandMoveCalc();

	bool isSprinting;
	bool HandSwave = false;
	bool LeftLegCollision = false;
	bool LeftLegTag = false;
	bool RightLegCollision = false;
	bool RightLegTag = false;
	bool JumpTriggered = false;
	int16 HandSwaveStage = 0;
	float ForwardMove;
	float CurrentFOV;
	float dTime;
	float PassTime;
	FVector HandsPosition;
	FVector HandsPositionL;
	FVector HandsPositionR;
	FVector HandsPositionJump;

	UCharacterMovementComponent* CharM = GetCharacterMovement();

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = "Hands")
	UStaticMeshComponent* Hands;
	UPROPERTY(EditAnywhere, Category = "LeftLegWall")
	USphereComponent* LLWall;
	UPROPERTY(EditAnywhere, Category = "RightLegWall")
	USphereComponent* RLWall;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
