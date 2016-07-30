// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MyProject.h"
#include "MyProjectGameMode.h"
#include "MyProjectPlayerController.h"

AMyProjectGameMode::AMyProjectGameMode()
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = AMyProjectPlayerController::StaticClass();
}
