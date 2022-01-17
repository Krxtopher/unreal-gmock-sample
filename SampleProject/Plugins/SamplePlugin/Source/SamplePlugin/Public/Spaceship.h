#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "Weapon.h"

#include "Spaceship.generated.h"

UCLASS()
class SAMPLEPLUGIN_API USpaceship : public UObject
{
	GENERATED_BODY()

public:
	/* This factory method creates a new instance and injects external 
	 * dependencies (primary for use when testing). 
	 * 
	 * In other frameworks, dependency injection is often accomodated by
	 * implementing overloaded constructors that accept the dependnecies.
	 * However, UE classes that extend UObject don't support overloaded 
	 * constructors, so this factory method approach is useful.
	 */
	static USpaceship* Create(FWeapon* weapon);

	USpaceship();

	void FireAt(FVector worldPosition);

private:
	FWeapon* Weapon;
};