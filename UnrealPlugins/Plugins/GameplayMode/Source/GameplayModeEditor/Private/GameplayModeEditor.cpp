#include "GameplayModeEditor.h"
#include "CoreMinimal.h"
#include "AssetToolsModule.h"
#include "ISettingsModule.h"
#include "GameplayModeAssetTools.h"
#include "Modules/ModuleManager.h"

void FGameplayModeEditorModule::StartupModule()
{
	AssetTools = MakeShareable(new FGameplayModeAssetTools);
	AssetTools->StartupModule();
}

void FGameplayModeEditorModule::ShutdownModule()
{
	AssetTools->ShutdownModule();
	AssetTools.Reset();
}

IMPLEMENT_GAME_MODULE(FGameplayModeEditorModule, GameplayModeEditor);
