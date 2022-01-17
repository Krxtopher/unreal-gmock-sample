#include "Spaceship.h"

USpaceship::USpaceship()
{
	Weapon = new FWeapon();
}

void USpaceship::FireAt(FVector worldPosition)
{
	Weapon->Fire();
}

USpaceship* USpaceship::Create(FWeapon* weapon)
{
	USpaceship* Ship = NewObject<USpaceship>();
	Ship->Weapon = weapon;
	return Ship;
}