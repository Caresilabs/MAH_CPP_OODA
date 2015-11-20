// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "StarWing.h"
#include "StarWingGameMode.h"

AStarWingGameMode::AStarWingGameMode() : isDead(false)
{
	// set default pawn class to our flying pawn
	//DefaultPawnClass = AStarWingPawn::StaticClass();
	time = START_TIME;
	health = 100.f;
	boost = 100.f;
}

void AStarWingGameMode::Tick(float DeltaSeconds)
{
	

	if ((time <= 0 || health <= 0)) {

		if ( isDead )
			return;

		


		//TSubclassOf<AStarWingPawn> ClassToFind;
		//TArray<AActor*> FoundActors;
		//UGameplayStatics::GetAllActorsOfClass( GetWorld(), ClassToFind, FoundActors );
		
		///if ( FoundActors.Num() == 0 )
		//	return;

		//AStarWingPawn*  pawn = Cast<AStarWingPawn>( DefaultPawnClass.GetDefaultObject() );
		
		//auto pawn = FoundActors[0];

		GameOver();


		auto pawn = Cast<AStarWingPawn>(UGameplayStatics::GetPlayerPawn( GetWorld(), 0 ));

		//pawn->Explosion->Activate( true );

		UGameplayStatics::SpawnEmitterAtLocation( GetWorld(), pawn->Explosion, pawn->GetActorLocation(), FRotator() );

		//pawn->PlaneMesh->SetVisibility( false );
		//pawn->SetActorTickEnabled( false );

		pawn->Destroy();


		isDead = true;

		//UGameplayStatics::OpenLevel(GetWorld(), "")
		//UGameplayStatics
		

		//UGameplayStatics::OpenLevel( GetWorld(), "MainMenu" );

		

		//UGameplayStatics::CreateParticleSystem( pawn->Explosion->get, GetWorld(), pawn, true );
		//auto partclSystem = CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("MyParticle"));
		//partclSystem->AttachTo(MeshVariable, "ASocketOfYourChoosing");
		//->cast
		//GetWorld()->findac
		//GetWorld()->SpawnActor()
	} else {
		boost += DeltaSeconds * BOOST_COST * 0.4f;
		time -= DeltaSeconds;
	}

	// Call any parent class Tick implementation
	Super::Tick(DeltaSeconds);
}
