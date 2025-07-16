// Fill out your copyright notice in the Description page of Project Settings.


#include "DronePawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"


ADronePawn::ADronePawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ADronePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADronePawn::Move);
        EnhancedInput->BindAction(MoveAction, ETriggerEvent::Completed, this, &ADronePawn::StopMove);
        EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADronePawn::Look);

        if (RollAction)
        {
            EnhancedInput->BindAction(RollAction, ETriggerEvent::Triggered, this, &ADronePawn::Roll);
        }
    }
}


void ADronePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ===== ȸ�� ó�� =====
    AddActorLocalRotation(FRotator(
        -RotationInput.Yaw * LookSpeed * DeltaTime,  // Pitch
        RotationInput.Roll * LookSpeed * DeltaTime,  // Yaw
        CurrentRollInput * RollSpeed * DeltaTime     // Roll
    ));

    bool bWasGrounded = bIsGrounded;

    // ===== ���� üũ =====
    FVector Start = GetActorLocation();
    FVector End = Start - FVector(0, 0, GroundCheckDistance);
    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bIsGrounded = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);


    // ===== �߷� ���� =====
    if (MovementInput.Z > 0.f)
    {
        // ��� �Է��� ������ �߷� ȿ�� ���� (�߷� �ӵ� �ʱ�ȭ)
        Velocity.Z = 0.f;
    }
    else
    {
        if (!bIsGrounded)
        {
            Velocity.Z += Gravity * DeltaTime;
            Velocity.Z = FMath::Max(Velocity.Z, TerminalVelocity);
        }
      
        else
        {
            if (Velocity.Z < 0.f)
                Velocity.Z = 0.f;
        }
    }

    // ===== �̵� ���� ��� (����� ���� ����) =====
    FVector Direction =
        GetActorForwardVector() * MovementInput.X +  // ���� X�� (�յ�)
        GetActorRightVector() * MovementInput.Y +  // ���� Y�� (�¿�)
        GetActorUpVector() * MovementInput.Z;   // ���� Z�� (����)

    // ===== �ӵ� ���� =====
    float SpeedMultiplier = bIsGrounded ? 1.0f : AirControlMultiplier;

    // ===== ���� �̵� ��� =====
    FVector HorizontalMove = Direction * MoveSpeed * SpeedMultiplier * DeltaTime;
    FVector GravityMove = FVector(0, 0, Velocity.Z * DeltaTime); // ���� ���� Z�� �ϰ�

    // ===== �̵� ���� =====
    AddActorWorldOffset(HorizontalMove, true);  // �浹 ���
    AddActorWorldOffset(GravityMove, true);     // �߷� ����


    // ===== ȸ�� �ʱ�ȭ ���� ���� =====
    if (!bWasGrounded && bIsGrounded)
    {
        bShouldResetRotation = true;
    }

    // ===== ȸ�� �ʱ�ȭ ���� =====
    if (bShouldResetRotation)
    {
        ResetRotationSmooth(DeltaTime);
    }


    // ===== �Է� �ʱ�ȭ =====
    RotationInput = FRotator::ZeroRotator;
    CurrentRollInput = 0.0f;
}

void ADronePawn::ResetRotationSmooth(float DeltaTime)
{
    FRotator CurrentRot = GetActorRotation();
    FRotator TargetRot = FRotator(0.f, CurrentRot.Yaw, 0.f);
    FRotator InterpRot = FMath::RInterpTo(CurrentRot, TargetRot, DeltaTime, 5.f); // �ӵ� 5

    SetActorRotation(InterpRot);

    if (FMath::Abs(InterpRot.Pitch) < 0.5f && FMath::Abs(InterpRot.Roll) < 0.5f)
    {
        bShouldResetRotation = false;
    }
}



void ADronePawn::Move(const FInputActionValue& Value)
{
    MovementInput = Value.Get<FVector>();
}

void ADronePawn::StopMove(const FInputActionValue& Value)
{
    MovementInput = FVector::ZeroVector;
}

void ADronePawn::Look(const FInputActionValue& Value)
{
    const FVector2D LookVal = Value.Get<FVector2D>();
    RotationInput.Roll = LookVal.X;
    RotationInput.Yaw = LookVal.Y;
}

void ADronePawn::Roll(const FInputActionValue& Value)
{
    CurrentRollInput = Value.Get<float>(); // Q = -1, E = +1
}

