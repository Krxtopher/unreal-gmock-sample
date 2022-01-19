#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SAMPLEPROJECT_API UWeapon : public UActorComponent
{
    GENERATED_BODY()

public:
    UWeapon();
    virtual ~UWeapon();

    /**
     * Fires this weapon.
     */
    virtual void Fire();
};
