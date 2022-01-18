#pragma once

#include "SampleProject/Public/Weapon.h"
#include "GoogleTest/include/gmock/gmock.h"

class UMockWeapon : public UWeapon
{
public:
	UMockWeapon() = default;
	virtual ~UMockWeapon() = default;

	MOCK_METHOD(void, Fire, (), (override));
};