#pragma once

#include <mutex>
#include "CoreMinimal.h"
#include "GoogleTest/include/gmock/gmock.h"
#include "GoogleTest/include/gtest/gtest.h"

using ::testing::UnitTest;

class GMockUEAdapter
{
public:

	static void Enable()
	{
		static std::once_flag isEnabled;
		std::call_once(isEnabled, []()
			{
				// Register a custom listener that adapts GTest failure events 
				// to UE error messages which the UE AutomationTest framework 
				// uses to detect test failures.
				UnitTest::GetInstance()->listeners()
					.Append(new GTestFailureReporter());
			});
	};

private:

	/**
	 * This class adapts GTest/GMock failure events so that they'll signal test
	 * failures in a way that the UE AutomationTest framework understands.
	 */
	class GTestFailureReporter : public testing::EmptyTestEventListener
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
};