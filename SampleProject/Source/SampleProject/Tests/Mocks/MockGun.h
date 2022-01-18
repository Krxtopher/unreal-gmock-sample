#pragma once

#include "GoogleTest/include/gmock/gmock.h"
#include "SampleProject/Public/Gun.h"

class MockGun : public Gun
{
public:
	MockGun() {}
	virtual ~MockGun() = default;

	MOCK_METHOD(void, Fire, (), (override));
};