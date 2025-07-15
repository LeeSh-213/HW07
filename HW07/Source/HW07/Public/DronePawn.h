// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "DronePawn.generated.h"

/**
 * 
 */
UCLASS()
class HW07_API ADronePawn : public ABasePawn
{
    GENERATED_BODY()

public:
    ADronePawn();

protected:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move(const FInputActionValue& Value);
    void StopMove(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void Roll(const FInputActionValue& Value);

    bool bIsGrounded = false;
    bool bShouldResetRotation = false;
    void ResetRotationSmooth(float DeltaTime);

private:
    FVector MovementInput;
    FRotator RotationInput;
    float CurrentRollInput = 0.0f;


    /** ȸ�� ���� �ӵ� (�������� ������ ����ġ) */
    float RotationResetSpeed = 3.0f;



    // �߷� �� ���� ó��
    FVector Velocity;

    UPROPERTY(EditDefaultsOnly, Category = "Flight")
	float Gravity = -980.0f; // �߷� ���ӵ� (cm/s^2)

	UPROPERTY(EditDefaultsOnly, Category = "Flight") // �߷� ���ӵ�
	float TerminalVelocity = -1000.0f; // �ִ� ���� �ӵ�

    UPROPERTY(EditDefaultsOnly, Category = "Flight")
    float GroundCheckDistance = 100.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Flight")
    float AirControlMultiplier = 0.4f;

    // �Է� ����
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* RollAction;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    float RollSpeed = 60.0f;
};

