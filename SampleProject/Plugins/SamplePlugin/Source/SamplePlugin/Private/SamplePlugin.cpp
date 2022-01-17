// Copyright Epic Games, Inc. All Rights Reserved.

#include "SamplePlugin.h"
#include "../Public/Tests/GMockUEAdapter.h"

#define LOCTEXT_NAMESPACE "FSamplePluginModule"


void FSamplePluginModule::StartupModule()
{
	// Enable GMock support.
	GMockUEAdapter::Enable();
}

void FSamplePluginModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSamplePluginModule, SamplePlugin)