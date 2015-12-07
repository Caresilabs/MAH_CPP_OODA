// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class STARWING_API ABullet : public AActor {
	GENERATED_BODY()

	UPROPERTY( Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true") )
	UStaticMeshComponent* StaticMesh;

	UFUNCTION() 
	void BeginOverlap( class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult );

public:
	// Sets default values for this actor's properties
	ABullet();

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//UFUNCTION()
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	void SetShooter( AActor* actor ) { shooter = actor; }
	void SetDirection( FVector dir ) { direction = dir; }
	void SetSpeed( float speed ) { this->speed = speed; }

private:
	AActor* shooter;
	FVector direction;
	float speed;

};
