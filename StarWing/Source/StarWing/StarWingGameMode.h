// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "StarWingPawn.h"

#include "GameFramework/GameMode.h"
#include "StarWingGameMode.generated.h"


UCLASS(minimalapi)
class AStarWingGameMode : public AGameMode
{
	GENERATED_BODY()



public:
	static const int START_TIME = 15;
	static const int CRASH_TIME_PENALTY = 20;
	static const int BOOST_COST = 15;


	UFUNCTION( BlueprintImplementableEvent )
	virtual void GameOver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Score)
	float time;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float boost;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	bool isRunning;

	AStarWingGameMode();

	virtual void Tick(float DeltaSeconds) override;

};



