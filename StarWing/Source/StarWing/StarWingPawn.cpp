// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "StarWing.h"
#include "StarWingPawn.h"

AStarWingPawn::AStarWingPawn()
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/Flying/Meshes/UFO.UFO"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create static mesh component
	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneMesh0"));
	PlaneMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());
	RootComponent = PlaneMesh;

	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->AttachTo(RootComponent);
	SpringArm->TargetArmLength = 160.0f; // The camera follows at this distance behind the character	
	SpringArm->SocketOffset = FVector(0.f,0.f,60.f);
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 15.f;

	// Create camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->AttachTo(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // Don't rotate camera with controller

	// Movement
	//MovementComponent = 		CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	//	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	//>AddInputVector(pawn->GetActorForwardVector()*velocity.X*DeltaTime);

	// Set handling parameters
	Acceleration = 500.f;
	TurnSpeed = 900.f;
	MaxSpeed = 4000.f;
	MinSpeed = 500.f;
	CurrentForwardSpeed = 500.f;
}

void AStarWingPawn::Tick(float DeltaSeconds)
{
	const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaSeconds,0,0);

	// Move plan forwards (with sweep so we stop when we collide with things)
	AddActorLocalOffset(LocalMove, true);
	//Movement->AddInputVector(LocalMove);
	AddActorWorldOffset(FVector(0, CurrentRightSpeed * DeltaSeconds, CurrentUpSpeed * DeltaSeconds));

	// Calculate change in rotation this frame
	FRotator DeltaRotation(0,0,0);
	//DeltaRotation.Pitch = CurrentPitchSpeed * DeltaSeconds;
	//DeltaRotation.Yaw = CurrentYawSpeed * DeltaSeconds;
	DeltaRotation.Roll = CurrentRollSpeed * DeltaSeconds;

	// Rotate plane
	AddActorLocalRotation(DeltaRotation);

	// Call any parent class Tick implementation
	Super::Tick(DeltaSeconds);
}

void AStarWingPawn::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	// Set velocity to zero upon collision
	CurrentForwardSpeed = 0.f;
	CurrentRightSpeed = 0.f;
	CurrentUpSpeed = 0.f;
}


void AStarWingPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	// Bind our control axis' to callback functions
	InputComponent->BindAxis("Thrust", this, &AStarWingPawn::ThrustInput);
	InputComponent->BindAxis("MoveUp", this, &AStarWingPawn::MoveUpInput);
	InputComponent->BindAxis("MoveRight", this, &AStarWingPawn::MoveRightInput);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &AStarWingPawn::ShootInput);
	InputComponent->BindAction("Roll", IE_Pressed, this, &AStarWingPawn::RollInput);
}

void AStarWingPawn::ThrustInput(float Val)
{
	// Is there no input?
	bool bHasInput = !FMath::IsNearlyEqual(Val, 0.f);
	// If input is not held down, reduce speed
	float CurrentAcc = bHasInput ? (Val * Acceleration) : (-0.5f * Acceleration);
	// Calculate new speed
	float NewForwardSpeed = CurrentForwardSpeed + (GetWorld()->GetDeltaSeconds() * CurrentAcc);
	// Clamp between MinSpeed and MaxSpeed
	CurrentForwardSpeed = FMath::Clamp(NewForwardSpeed, MinSpeed, MaxSpeed);
}

void AStarWingPawn::MoveUpInput(float Val)
{
	// Target pitch speed is based in input
	float TargetSpeed = (Val * TurnSpeed);

	// When steering, we decrease pitch slightly
	TargetSpeed += (FMath::Abs(CurrentRightSpeed) * -0.2f);

	// Smoothly interpolate to target pitch speed
	CurrentUpSpeed = FMath::FInterpTo(CurrentUpSpeed, TargetSpeed, GetWorld()->GetDeltaSeconds(), 2.f);
}

void AStarWingPawn::MoveRightInput(float Val)
{
	/*
	// Target yaw speed is based on input
	float TargetYawSpeed = (Val * TurnSpeed);

	// Smoothly interpolate to target yaw speed
	CurrentYawSpeed = FMath::FInterpTo(CurrentYawSpeed, TargetYawSpeed, GetWorld()->GetDeltaSeconds(), 2.f);

	// Is there any left/right input?
	const bool bIsTurning = FMath::Abs(Val) > 0.2f;

	// If turning, yaw value is used to influence roll
	// If not turning, roll to reverse current roll value
	float TargetRollSpeed = bIsTurning ? (CurrentYawSpeed * 0.5f) : (GetActorRotation().Roll * -2.f);

	// Smoothly interpolate roll speed
	CurrentRollSpeed = FMath::FInterpTo(CurrentRollSpeed, TargetRollSpeed, GetWorld()->GetDeltaSeconds(), 2.f);
	*/
	float TargetSpeed = (Val * TurnSpeed);
	CurrentRightSpeed = FMath::FInterpTo(CurrentRightSpeed, TargetSpeed, GetWorld()->GetDeltaSeconds(), 2.f);

	// Is there any left/right input?
	const bool bIsTurning = FMath::Abs(Val) > 0.2f;

	float TargetRollSpeed = (GetActorRotation().Roll * -2.f); //bIsTurning ? (CurrentRightSpeed * 0.5f) : 
	CurrentRollSpeed = FMath::FInterpTo(CurrentRollSpeed, TargetRollSpeed, GetWorld()->GetDeltaSeconds(), 5.f);
}

void AStarWingPawn::ShootInput(){

}


void AStarWingPawn::RollInput() {
	CurrentRollSpeed = 1750 * (CurrentRightSpeed < 0 ? -1 : 1);
	CurrentRightSpeed *= 2.f;
}

