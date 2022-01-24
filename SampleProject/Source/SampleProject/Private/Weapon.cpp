#include "Weapon.h"

UWeapon::UWeapon()
{
    PrimaryComponentTick.bCanEverTick = false;
}

UWeapon::~UWeapon()
{
}

void UWeapon::Fire()
{
    UE_LOG(LogTemp, Display, TEXT("Weapon fired"));
}

