// Copyright Epic Games, Inc. All Rights Reserved.

#include "SamplePlugin.h"
#include "TestFailureReporter.h"

#define LOCTEXT_NAMESPACE "FSamplePluginModule"

void FSamplePluginModule::StartupModule()
{
	::testing::TestEventListeners& Listeners = ::testing::UnitTest::GetInstance()->listeners();
	Listeners.Append(new TestFailureReporter());
}

void FSamplePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSamplePluginModule, SamplePlugin)