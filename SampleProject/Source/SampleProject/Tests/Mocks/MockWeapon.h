/*
This example shows how to mock any class that extends UObject.
*/
#pragma once

#include "GoogleTest/include/gmock/gmock.h"
#include "SampleProject/Public/Weapon.h"
#include "MockWeapon.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SAMPLEPROJECT_API UMockWeapon : public UWeapon
{
	GENERATED_BODY()

public:
	MOCK_METHOD(void, Fire, (), (override));
};