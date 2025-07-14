// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/ArrowComponent.h" 
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);
	Mesh->SetSimulatePhysics(false);


	ForwardArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ForwardArrow"));
	ForwardArrow->SetupAttachment(RootComponent);
	ForwardArrow->ArrowSize = 2.f;              // 화살표 크기 조절
	ForwardArrow->SetRelativeLocation(FVector(0.f, 0.f, 50.f));  // 약간 위쪽 위치에 배치
	ForwardArrow->SetRelativeRotation(FRotator::ZeroRotator);

	bUseControllerRotationYaw = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SocketOffset = FVector(0.f, 0.f, 50.f); // 카메라 약간 위쪽 위치
	SpringArm->SetRelativeRotation(FRotator::ZeroRotator);

	bUseControllerRotationYaw = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	ControlRotation = FRotator::ZeroRotator;

}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();

	// Enhanced Input 매핑 등록
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasePawn::Move);
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Completed, this, &ABasePawn::StopMove);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABasePawn::Look);
	}
}

void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!LookInput.IsZero())
	{
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FRotator CtrlRot = PC->GetControlRotation();
			CtrlRot.Yaw += LookInput.X * LookSpeed * DeltaTime;
			CtrlRot.Pitch = FMath::Clamp(CtrlRot.Pitch - LookInput.Y * LookSpeed * DeltaTime, -80.f, 80.f);
			CtrlRot.Roll = 0.f;
			PC->SetControlRotation(CtrlRot);
		}
	}

	// 이동 처리
	if (!MovementInput.IsZero())
	{
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			const FRotator YawRotation(0.f, PC->GetControlRotation().Yaw, 0.f);
			const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			const FVector MoveDir = Forward * MovementInput.X + Right * MovementInput.Y;
			AddActorWorldOffset(MoveDir * MoveSpeed * DeltaTime, true);

			SetActorRotation(FRotator(0.f, PC->GetControlRotation().Yaw, 0.f));

		}
	}

	LookInput = FVector2D::ZeroVector;
}


void ABasePawn::Move(const FInputActionValue& Value)
{
	MovementInput = Value.Get<FVector2D>();
}

void ABasePawn::StopMove(const FInputActionValue& Value)
{
	MovementInput = FVector2D::ZeroVector;
}

void ABasePawn::Look(const FInputActionValue& Value)
{
	LookInput = Value.Get<FVector2D>();
}

