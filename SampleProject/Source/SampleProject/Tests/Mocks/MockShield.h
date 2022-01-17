#pragma once

#include "GoogleTest/include/gmock/gmock.h"

#include "Shield.h"

class MockShield : public FShield
{
public:
	MOCK_METHOD(void, SetPower, (float), (override));
};
