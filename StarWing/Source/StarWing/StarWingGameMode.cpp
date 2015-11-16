// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "StarWing.h"
#include "StarWingGameMode.h"
#include "StarWingPawn.h"

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
	boost += DeltaSeconds;
	time -= DeltaSeconds;

	if (time <= 0) {
		//DefaultPawnClass->poss
		//Cast<AStarWingPawn>(DefaultPawnClass)->Destroy();


		//UGameplayStatics::SpawnEmitterAtLocation()
		//auto partclSystem = CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("MyParticle"));
		//partclSystem->AttachTo(MeshVariable, "ASocketOfYourChoosing");
		//->cast
		//GetWorld()->findac
		//GetWorld()->SpawnActor()
	}

	// Call any parent class Tick implementation
	Super::Tick(DeltaSeconds);
}
