// Fill out your copyright notice in the Description page of Project Settings.
#include "Toolbar/FoolishGameCommands.h"
#define LOCTEXT_NAMESPACE "Foolish Game Editor"

void FFoolishGameCommands::RegisterCommands()
{
	UI_COMMAND(ToolbarAction, "Foolish Game", "Foolish Game functional actions.", EUserInterfaceActionType::Button,
	           FInputChord());
	UI_COMMAND(GenerateTables, "Generate Tables", "Generate tables from setting path.",
	           EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(FrameworkSettings, "Framework Settings", "Modify the framework settings.",
	           EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(FoolishGameEditor, "Foolish Game Editor", "Config the foolish game settings.",
	           EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(WorldCreatorSettings, "World Creator Settings", "Modify the world creator settings.",
	           EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(OpenPuzzleGeneratorWindow, "Puzzle Creator", "Create puzzle groups", EUserInterfaceActionType::Button,
	           FInputChord());
}
#undef LOCTEXT_NAMESPACE
