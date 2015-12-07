// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "StarWing.h"
#include "StarWingGameMode.h"

AStarWingGameMode::AStarWingGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AStarWingPawn::StaticClass();
	time = START_TIME;
	health = 100.f;
	boost = 100.f;
}

void AStarWingGameMode::Tick(float DeltaSeconds)
{

	if ( isRunning ) {

		if ( (time <= 0 || health <= 0) ) {

			auto pawn = Cast<AStarWingPawn>( UGameplayStatics::GetPlayerPawn( GetWorld(), 0 ) );

			UGameplayStatics::SpawnEmitterAtLocation( GetWorld(), pawn->Explosion, pawn->GetActorLocation());

			pawn->Destroy();


			isRunning = false;

			GameOver();

		} else {
			boost += DeltaSeconds * BOOST_COST * 0.4f;
			time -= DeltaSeconds;
		}
	}

	// Call any parent class Tick implementation
	Super::Tick( DeltaSeconds );
}
