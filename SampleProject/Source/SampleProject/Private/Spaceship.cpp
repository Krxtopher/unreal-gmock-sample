// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ASpaceship* ASpaceship::Create(UWeapon* weapon)
{
	ASpaceship* ship = NewObject<ASpaceship>();
	ship->Weapon = weapon;
	return ship;
}