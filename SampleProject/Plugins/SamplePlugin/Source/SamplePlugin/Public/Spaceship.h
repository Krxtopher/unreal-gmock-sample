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
	USpaceship();
	USpaceship(FWeapon* weapon);

private:
	FWeapon* Weapon;
};