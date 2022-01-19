// Copyright Epic Games, Inc. All Rights Reserved.

#include "GMock.h"
#include "GMockUEAdapter.h"

#define LOCTEXT_NAMESPACE "FGMockModule"

void FGMockModule::StartupModule()
{
    
}

void FGMockModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGMockModule, GMock)