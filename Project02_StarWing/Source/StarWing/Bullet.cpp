// Fill out your copyright notice in the Description page of Project Settings.

#include "StarWing.h"
#include "Bullet.h"
#include "StarWingPawn.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	struct FConstructorStatics {
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> BulletMesh;
		FConstructorStatics()
			: BulletMesh( TEXT( "StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'" ) ) {
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create static mesh component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Bullet Mesh" ) );
	StaticMesh->SetStaticMesh( ConstructorStatics.BulletMesh.Get() );
	StaticMesh->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));

	StaticMesh->OnComponentBeginOverlap.AddDynamic( this, &ABullet::BeginOverlap );
	StaticMesh->SetCollisionObjectType( ECollisionChannel::ECC_GameTraceChannel1 );

	//StaticMesh->SetNotifyRigidBodyCollision( true );
	//StaticMesh->SetEnableGravity( false );

	RootComponent = StaticMesh;
}

// Called every frame
void ABullet::Tick( float DeltaTime )
{
	AddActorLocalOffset( FVector( direction * speed * DeltaTime ) , true);

	Super::Tick( DeltaTime );
}

void ABullet::BeginOverlap( class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult ) { 

	if ( Cast<AStarWingPawn>(OtherActor) )
		return;

	if ( OtherComp->ComponentHasTag( TEXT( "Destroyable" ) ) ) {
		OtherActor->Destroy();
	}

	this->Destroy();

}

void ABullet::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if ( Cast<AStarWingPawn>(Other) )
		return;

	if ( OtherComp->ComponentHasTag( TEXT( "Destroyable" ) ) ) {
		Other->Destroy();
	}

	this->Destroy();
}

