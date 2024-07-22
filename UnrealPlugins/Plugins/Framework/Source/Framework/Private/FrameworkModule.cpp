#include "FrameworkModule.h"

//#include "ContentBrowserModule.h"
//#include "ToolMenus.h"
#include "FrameworkSettings.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FFrameworkModule, Framework);

void FFrameworkModule::StartupModule()
{
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FFrameworkModule::OnPostEngineInit);
}

void FFrameworkModule::ShutdownModule()
{
	// if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	// {
	// 	SettingsModule->UnregisterSettings(TEXT("Project"),
	// 	                                   TEXT("Foolish Game"),
	// 	                                   TEXT("Framework"));
	// }
	//
	// FCoreDelegates::OnPostEngineInit.RemoveAll(this);
}

void FFrameworkModule::OnPostEngineInit()
{
	// if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	// {
	// 	SettingsModule->RegisterSettings(TEXT("Project"),
	// 									 TEXT("Foolish Game"),
	// 									 TEXT("Framework"),
	// 									 FText::FromString(TEXT("Settings")),
	// 									 FText::FromString(TEXT("Framework Settings")),
	// 									 GetMutableDefault<UFrameworkSettings>());
	// }
}

//void FFramework::SetupEditModule()
//{
//	FContentBrowserModule& contentBroModule = FModuleManager::LoadModuleChecked<
//		FContentBrowserModule>("ContentBrowser");
//	contentBroModule.GetAllPathViewContextMenuExtenders().Add(
//		FContentBrowserMenuExtender_SelectedPaths::CreateRaw(this, &FFramework::AddPathExtender));
//}

//TSharedRef<FExtender> FFramework::AddPathExtender(const TArray<FString>& Strings)
//{
//	TSharedPtr<FExtender> tempExtender = MakeShareable(new FExtender());
//	tempExtender->AddMenuExtension(
//		"PathContextBulkOperations", EExtensionHook::First,
//		TSharedPtr<FUICommandList>(),
//		FMenuExtensionDelegate::CreateRaw(this, &FFramework::AddMenuEntry)
//	);
//	return tempExtender.ToSharedRef();
//}

//void FFramework::AddMenuEntry(FMenuBuilder& MenuBuilder)
//{
//	MenuBuilder.AddSubMenu(
//		FText::FromString(TEXT("Framework")),
//		FText::FromString(TEXT("Config")),
//		FNewMenuDelegate::CreateRaw(this, &FFramework::CreateConfig),
//		FUIAction(
//			FExecuteAction(),
//			FCanExecuteAction::CreateLambda([=]()-> bool { return true; })
//		),
//		NAME_None,
//		EUserInterfaceActionType::Button,
//		false,
//		FSlateIcon()
//	);
//}

//void FFramework::CreateConfig(FMenuBuilder& MenuBuilder)
//{
//	
//}
