// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "Spaceship.generated.h"

UCLASS()
class SAMPLEPROJECT_API ASpaceship : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceship();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UWeapon* Weapon;

// Static members

public: 
	/**
	 * Factory function that returns a new ASpaceship instance. This is 
	 * primarily used during testing as a mechanism to inject dependencies.
	 */
	static ASpaceship* Create(UWeapon* weapon);
};
