#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SAMPLEPROJECT_API UWeapon : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeapon();
	virtual ~UWeapon() = default;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * Fires this weapon.
	 */
	virtual void Fire();

protected:
	virtual void BeginPlay() override;

};
