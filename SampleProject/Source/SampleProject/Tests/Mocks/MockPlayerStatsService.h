// This class demonstrates the pattern for mocking interfaces or classes that 
// do not extend UObject.

#pragma once

#include "GoogleTest/include/gmock/gmock.h"
#include "SampleProject/Public/IPlayerStatsService.h"

class SAMPLEPROJECT_API FMockPlayerStatsService : public IPlayerStatsService
{
public:
	MOCK_METHOD(void, RecordWeaponFire, (), (override));
};