#include "Spaceship.h"

ASpaceship::ASpaceship()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ASpaceship::FireAt(const FVector WorldPosition)
{
    Weapon->Fire();
    PlayerStats->RecordWeaponFire();
}

ASpaceship* ASpaceship::Create(UWeapon* Weapon, IPlayerStatsService* PlayerStats)
{
    ASpaceship* Ship = NewObject<ASpaceship>();
    Ship->Weapon = Weapon;
    Ship->PlayerStats = PlayerStats;
    return Ship;
}