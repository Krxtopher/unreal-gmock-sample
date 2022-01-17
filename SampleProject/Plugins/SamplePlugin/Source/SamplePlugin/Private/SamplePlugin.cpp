// Copyright Epic Games, Inc. All Rights Reserved.

#include "SamplePlugin.h"
#include "Tests/GTestFailureReporter.h"

#define LOCTEXT_NAMESPACE "FSamplePluginModule"

using ::testing::UnitTest;

void FSamplePluginModule::StartupModule()
{
	// Register a custom listener that adapts GTest failure events
	// to UE Functional Test error messages.
	UnitTest::GetInstance()->listeners()
		.Append(new GTestFailureReporter());
}

void FSamplePluginModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSamplePluginModule, SamplePlugin)