#pragma once

#include "CoreMinimal.h"

#include "GoogleTest/include/gmock/gmock.h"
#include "GoogleTest/include/gtest/gtest.h"

/**
 * This class adapts GTest failure events so that they'll signal test failures
 * in a way that the UE Functional Testing framework understands.
*/
class TestFailureReporter : public testing::EmptyTestEventListener
{
	void OnTestPartResult(const testing::TestPartResult& result) override
	{
		if (result.type() == testing::TestPartResult::kFatalFailure
			|| result.type() == testing::TestPartResult::kNonFatalFailure)
		{
			const auto Message = FString(result.message());
			UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
		}
	}
};