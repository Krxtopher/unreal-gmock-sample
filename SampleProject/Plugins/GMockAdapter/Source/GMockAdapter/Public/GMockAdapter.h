// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <mutex>
#include "CoreMinimal.h"
#include "GoogleTest/include/gmock/gmock.h"
#include "GoogleTest/include/gtest/gtest.h"

using ::testing::UnitTest;

class FGMockAdapterModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

/**
 * This class adapts the standard GMock library to work with the UE
 * Automation Tests framework.
 *
 * To enable GMock support in your tests, call the `GMockAdapter::Enable()`
 * static method before any of your tests execute.
 */
class FGMockAdapter
{
public:

    static void Enable()
    {
        static std::once_flag isEnabled;
        std::call_once(isEnabled, []()
        {
            // Register a custom listener that adapts GTest failure events 
            // to UE error messages which the UE Automation Tests framework 
            // uses to detect test failures.
            UnitTest::GetInstance()->listeners()
                .Append(new GTestFailureReporter());
        });
    };

private:

    /**
     * This private class adapts GTest/GMock failure events so that they'll signal test
     * failures in a way that the UE Automation Tests framework understands.
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