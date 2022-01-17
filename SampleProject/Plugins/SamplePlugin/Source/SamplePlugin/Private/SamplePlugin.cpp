// Copyright Epic Games, Inc. All Rights Reserved.

#include "SamplePlugin.h"
#include "../Public/Tests/GTestFailureReporter.h"

#define LOCTEXT_NAMESPACE "FSamplePluginModule"

using ::testing::UnitTest;

void FSamplePluginModule::StartupModule()
{
	// Register a custom listener that adapts GTest failure events to UE error 
	// messages which the UE AutomationTest framework uses to detect test
	// failures.
	UnitTest::GetInstance()->listeners()
		.Append(new GTestFailureReporter());
}

void FSamplePluginModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSamplePluginModule, SamplePlugin)