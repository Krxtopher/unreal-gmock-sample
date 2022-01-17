#pragma once

#include "Weapon.h"
#include "GoogleTest/include/gmock/gmock.h"

class MockWeapon : public FWeapon
{
public:
	MOCK_METHOD(void, Fire, (), (override));
};