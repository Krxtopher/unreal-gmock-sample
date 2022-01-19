#include "Spaceship.h"

ASpaceship::ASpaceship()
{
 	PrimaryActorTick.bCanEverTick = false;
}

void ASpaceship::FireAt(FVector WorldPosition)
{
	Weapon->Fire();
}

ASpaceship* ASpaceship::Create(UWeapon* Weapon, IPlayerStatsService* PlayerStats)
{
	ASpaceship* Ship = NewObject<ASpaceship>();
	Ship->Weapon = Weapon;
	Ship->PlayerStats = PlayerStats;
	return Ship;
}