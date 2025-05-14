// Copyright Epic Games, Inc. All Rights Reserved.

#include "Arcane_ArcherGameMode.h"
#include "Arcane_ArcherCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArcane_ArcherGameMode::AArcane_ArcherGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
