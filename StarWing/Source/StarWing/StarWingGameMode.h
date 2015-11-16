// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "StarWingGameMode.generated.h"

UCLASS(minimalapi)
class AStarWingGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	static const int START_TIME = 30;
	static const int CRASH_TIME_PENALTY = 10;
	static const int BOOST_COST = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Score)
	float time;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float boost;

	AStarWingGameMode();

	virtual void Tick(float DeltaSeconds) override;
};



