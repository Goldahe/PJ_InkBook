// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MainPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class INKBOOK_API AMainPlayer : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AMainPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay();


public:
	virtual void Tick(float DeltaTime);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);


private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void HoriRot(float Value);
	void VertRot(float Value);
	void Jump();

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Capsule")
	UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere, Category = "Capsule")
	USpringArmComponent* SpringArm;

	int32 JumpCount = 0;
};
