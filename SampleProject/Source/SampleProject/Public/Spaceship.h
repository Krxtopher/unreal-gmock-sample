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
	ASpaceship();

	/** Causes the ship to fire its weapon toward the indicated coordinate. */
	virtual void FireAt(FVector WorldPosition);

private:
	/** A reference to the ship's main weapon. */
	UWeapon* Weapon;

// Static members

public: 
	/** 
	Factory function that returns a new ASpaceship instance. This is 
	primarily used during testing as a mechanism to inject dependencies.
	*/
	static ASpaceship* Create(UWeapon* Weapon);
};
