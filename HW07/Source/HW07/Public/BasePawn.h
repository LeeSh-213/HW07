// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "BasePawn.generated.h"



UCLASS()
class HW07_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StopMove(const FInputActionValue& Value);


	FVector2D MovementInput;
	FVector2D LookInput;

	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* ForwardArrow;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float MoveSpeed = 300.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float LookSpeed = 100.0f;

	FRotator ControlRotation;



};
