// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "StarWing.h"
#include "StarWingGameMode.h"
#include "StarWingPawn.h"

AStarWingGameMode::AStarWingGameMode() : isDead(false)
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AStarWingPawn::StaticClass();
	time = START_TIME;
	health = 100.f;
	boost = 100.f;
}

void AStarWingGameMode::Tick(float DeltaSeconds)
{
	

	if ((time <= 0 || health <= 0) && !isDead) {

		AStarWingPawn*  pawn = Cast<AStarWingPawn>( DefaultPawnClass.GetDefaultObject() );
		pawn->Explosion->Activate( true );

		//pawn->PlaneMesh->SetVisibility( false );
		//pawn->SetActorTickEnabled( false );

		pawn->Destroy();


		isDead = true;

		//UGameplayStatics::CreateParticleSystem( pawn->Explosion->get, GetWorld(), pawn, true );
		//auto partclSystem = CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("MyParticle"));
		//partclSystem->AttachTo(MeshVariable, "ASocketOfYourChoosing");
		//->cast
		//GetWorld()->findac
		//GetWorld()->SpawnActor()
	} else {
		boost += DeltaSeconds;
		time -= DeltaSeconds;
	}

	// Call any parent class Tick implementation
	Super::Tick(DeltaSeconds);
}
