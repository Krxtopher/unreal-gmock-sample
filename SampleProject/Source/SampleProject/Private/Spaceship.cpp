#include "Spaceship.h"

ASpaceship::ASpaceship()
{
 	PrimaryActorTick.bCanEverTick = false;
}

void ASpaceship::FireAt(FVector WorldPosition)
{
	Weapon->Fire();
}

ASpaceship* ASpaceship::Create(UWeapon* weapon)
{
	ASpaceship* ship = NewObject<ASpaceship>();
	ship->Weapon = weapon;
	return ship;
}