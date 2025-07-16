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

    // ===== 회전 처리 =====
    AddActorLocalRotation(FRotator(
        -RotationInput.Yaw * LookSpeed * DeltaTime,  // Pitch
        RotationInput.Roll * LookSpeed * DeltaTime,  // Yaw
        CurrentRollInput * RollSpeed * DeltaTime     // Roll
    ));

    bool bWasGrounded = bIsGrounded;

    // ===== 지면 체크 =====
    FVector Start = GetActorLocation();
    FVector End = Start - FVector(0, 0, GroundCheckDistance);
    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bIsGrounded = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);


    // ===== 중력 적용 =====
    if (MovementInput.Z > 0.f)
    {
        // 상승 입력이 있으면 중력 효과 제거 (중력 속도 초기화)
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

    // ===== 이동 방향 계산 (드론의 로컬 기준) =====
    FVector Direction =
        GetActorForwardVector() * MovementInput.X +  // 로컬 X축 (앞뒤)
        GetActorRightVector() * MovementInput.Y +  // 로컬 Y축 (좌우)
        GetActorUpVector() * MovementInput.Z;   // 로컬 Z축 (상하)

    // ===== 속도 보정 =====
    float SpeedMultiplier = bIsGrounded ? 1.0f : AirControlMultiplier;

    // ===== 최종 이동 계산 =====
    FVector HorizontalMove = Direction * MoveSpeed * SpeedMultiplier * DeltaTime;
    FVector GravityMove = FVector(0, 0, Velocity.Z * DeltaTime); // 월드 기준 Z축 하강

    // ===== 이동 적용 =====
    AddActorWorldOffset(HorizontalMove, true);  // 충돌 고려
    AddActorWorldOffset(GravityMove, true);     // 중력 적용


    // ===== 회전 초기화 시작 조건 =====
    if (!bWasGrounded && bIsGrounded)
    {
        bShouldResetRotation = true;
    }

    // ===== 회전 초기화 보간 =====
    if (bShouldResetRotation)
    {
        ResetRotationSmooth(DeltaTime);
    }


    // ===== 입력 초기화 =====
    RotationInput = FRotator::ZeroRotator;
    CurrentRollInput = 0.0f;
}

void ADronePawn::ResetRotationSmooth(float DeltaTime)
{
    FRotator CurrentRot = GetActorRotation();
    FRotator TargetRot = FRotator(0.f, CurrentRot.Yaw, 0.f);
    FRotator InterpRot = FMath::RInterpTo(CurrentRot, TargetRot, DeltaTime, 5.f); // 속도 5

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

