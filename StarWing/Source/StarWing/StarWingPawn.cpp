// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "StarWing.h"
#include "StarWingPawn.h"
#include "StarWingGameMode.h"
#include "Bullet.h"

AStarWingPawn::AStarWingPawn()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		ConstructorHelpers::FObjectFinderOptional<UParticleSystem> Explosion;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/Flying/Meshes/UFO.UFO")), 
				Explosion(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"))
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
	SpringArm->TargetArmLength = 250.0f; // The camera follows at this distance behind the character	
	SpringArm->SocketOffset = FVector(0.f,0.f,60.f);
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 15.f;

	// Create camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->AttachTo(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // Don't rotate camera with controller


	//Explosion = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Explosions"));
	if ( ConstructorStatics.Explosion.Succeeded() ) {
		//Explosion->SetTemplate( ConstructorStatics.Explosion.Get() );
		Explosion = ConstructorStatics.Explosion.Get();
		//Explosion->Deactivate();
	}
	//Explosion->AttachTo(RootComponent);
	
	// Set handling parameters
	Acceleration = 800.f;
	TurnSpeed = 1500.f;
	MaxSpeed = 2800.f;
	MinSpeed = 300.f;
	CurrentForwardSpeed = 500.f;

}

void AStarWingPawn::Tick(float DeltaSeconds)
{
	const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaSeconds,0,0);

	// Move plan forwards (with sweep so we stop when we collide with things)
	AddActorLocalOffset(LocalMove, true);

	AddActorWorldOffset(FVector(0, CurrentRightSpeed * DeltaSeconds, CurrentUpSpeed * DeltaSeconds), true);

	// Calculate change in rotation this frame
	FRotator DeltaRotation(0,0,0);
	DeltaRotation.Pitch = CurrentPitchSpeed * DeltaSeconds;
	DeltaRotation.Yaw = -GetActorRotation().Yaw * DeltaSeconds;	// CurrentYawSpeed * DeltaSeconds;
	DeltaRotation.Roll = CurrentRollSpeed * DeltaSeconds;

	// Rotate plane
	AddActorLocalRotation(DeltaRotation);

	// Call any parent class Tick implementation
	Super::Tick(DeltaSeconds);
}


void AStarWingPawn::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if ( Cast<ABullet>(Other) != nullptr )
		return;
	
	if (OtherComp->ComponentHasTag(TEXT("Destroyable"))) {
		// Set velocity to zero upon collision
		CurrentForwardSpeed = 0.f;
		CurrentRightSpeed = 0.f;
		CurrentUpSpeed = 0.f;
		Other->Destroy();
	} else {
		//CurrentUpSpeed = MaxSpeed / 4.f;
		///CurrentForwardSpeed *= -1.f;
		//CurrentRightSpeed *= -1.f;
		CurrentForwardSpeed = HitNormal.X * 1500.f;
		CurrentRightSpeed = HitNormal.Y * 1500.f;
		CurrentUpSpeed = HitNormal.Z * 1500.f;
	}

	AStarWingGameMode* gm = (AStarWingGameMode*)GetWorld()->GetAuthGameMode();
	gm->health -= AStarWingGameMode::CRASH_TIME_PENALTY;
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
	AStarWingGameMode* gm = (AStarWingGameMode*)GetWorld()->GetAuthGameMode();
	if (gm->boost <= 0)
		return;

	gm->boost -= AStarWingGameMode::BOOST_COST * GetWorld()->DeltaTimeSeconds * Val; //((Val*2)-1.f
	gm->boost = FMath::Clamp(gm->boost, 0.f, 100.f);

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

	float TargetPitchSpeed = 0.f;
	const bool bIsTurning = FMath::Abs(Val) > 0.2f;
	if (bIsTurning) {
		TargetPitchSpeed = ((CurrentUpSpeed < 0 ? -20 : 20) - GetActorRotation().Pitch);
	}
	CurrentPitchSpeed = FMath::FInterpTo(CurrentPitchSpeed, TargetPitchSpeed, GetWorld()->GetDeltaSeconds(), 5.f);

	// When steering, we decrease pitch slightly
	TargetSpeed += (FMath::Abs(CurrentRightSpeed) * -0.2f);

	// Smoothly interpolate to target pitch speed
	CurrentUpSpeed = FMath::FInterpTo(CurrentUpSpeed, TargetSpeed, GetWorld()->GetDeltaSeconds(), 2.f);
}

void AStarWingPawn::MoveRightInput(float Val)
{
	float TargetSpeed = (Val * TurnSpeed);
	CurrentRightSpeed = FMath::FInterpTo(CurrentRightSpeed, TargetSpeed, GetWorld()->GetDeltaSeconds(), 2.f);

	// Is there any left/right input?
	const bool bIsTurning = FMath::Abs(Val) > 0.2f;

	float TargetRollSpeed = (GetActorRotation().Roll * -2.f); //bIsTurning ? (CurrentRightSpeed * 0.5f) : 
	
	if (bIsTurning && CurrentRollSpeed < 400)
		TargetRollSpeed = (CurrentRightSpeed < 0 ? -20 : 20) - (GetActorRotation().Roll);

	CurrentRollSpeed = FMath::FInterpTo(CurrentRollSpeed, TargetRollSpeed, GetWorld()->GetDeltaSeconds(), 5.f);
}

void AStarWingPawn::ShootInput(){
	const FVector pos = PlaneMesh->GetSocketLocation( "ShootSocket" );
	const FRotator rot = PlaneMesh->GetSocketRotation( "ShootSocket" );

	ABullet* bullet = Cast<ABullet>(GetWorld()->SpawnActor( ABullet::StaticClass(), &pos, &rot ));
	bullet->SetShooter( this );
	bullet->SetDirection( GetActorForwardVector() );
	bullet->SetSpeed( CurrentForwardSpeed*9.0f );
}


void AStarWingPawn::RollInput() {
	
	AStarWingGameMode* gm = (AStarWingGameMode*)GetWorld()->GetAuthGameMode();
	if ( gm->boost - AStarWingGameMode::BOOST_COST /2.0f <= 0 )
		return;

	gm->boost -= AStarWingGameMode::BOOST_COST ;
	gm->boost = FMath::Clamp( gm->boost, 0.f, 100.f );

	CurrentRollSpeed = 1750 * (CurrentRightSpeed < 0 ? -1 : 1);
	CurrentRightSpeed = 3200.0f * (CurrentRightSpeed < 0 ? -1 : 1);
}

