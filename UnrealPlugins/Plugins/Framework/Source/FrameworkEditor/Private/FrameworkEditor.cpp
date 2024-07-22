#include "FrameworkEditor.h"
#include "CoreMinimal.h"
#include "AssetToolsModule.h"
#include "FoolishGameEditorSettings.h"
#include "FrameworkSettings.h"
#include "ISettingsModule.h"
#include "Modules/ModuleManager.h"

void FFrameworkEditorModule::StartupModule()
{
	//FCoreDelegates::OnPostEngineInit.AddRaw(this, &FFrameworkEditorModule::OnPostEngineInit);


	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(TEXT("Project"),
								 TEXT("Foolish Game"),
								 TEXT("Framework"),
								 FText::FromString(TEXT("Settings")),
								 FText::FromString(TEXT("Framework Settings")),
								 GetMutableDefault<UFrameworkSettings>());
		SettingsModule->RegisterSettings(TEXT("Project"),
		                                 TEXT("Foolish Game"),
		                                 TEXT("Foolish Game Editor"),
		                                 FText::FromString(TEXT("Editor")),
		                                 FText::FromString(TEXT("Foolish Game Editor")),
		                                 GetMutableDefault<UFoolishGameEditorSettings>());
	}
	FoolishGameToolbar = MakeShareable(new FFoolishGameToolbar);
	FoolishGameToolbar->StartupModule();
	AssetTools = MakeShareable(new FFrameworkAssetTools);
	AssetTools->StartupModule();
}

void FFrameworkEditorModule::ShutdownModule()
{
	AssetTools->ShutdownModule();
	AssetTools.Reset();
	FoolishGameToolbar->ShutdownModule();
	FoolishGameToolbar.Reset();

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings(TEXT("Project"),
		                                   TEXT("Foolish Game"),
		                                   TEXT("Foolish Game Editor"));
		SettingsModule->UnregisterSettings(TEXT("Project"),
								   TEXT("Foolish Game"),
								   TEXT("Framework"));
	}

	FCoreDelegates::OnPostEngineInit.RemoveAll(this);
}

void FFrameworkEditorModule::OnPostEngineInit()
{
	FoolishGameToolbar->StartupModule();
}

IMPLEMENT_GAME_MODULE(FFrameworkEditorModule, FrameworkEditor);
