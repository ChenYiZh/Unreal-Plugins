#include "Toolbar/FoolishGameToolbar.h"

#include "ISettingsModule.h"
#include "Toolbar/FoolishGameStyle.h"
#include "Toolbar/FoolishGameCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "Interfaces/IPluginManager.h"
#include "Toolbar/Actions/MenuAction_GenerateTables.h"

static const FName FoolishGameToolbarTabName("FoolishGameToolbar");

#define LOCTEXT_NAMESPACE "Framework Editor"

void FFoolishGameToolbar::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FFoolishGameStyle::Initialize();
	FFoolishGameStyle::ReloadTextures();

	FFoolishGameCommands::Register();

	CommandList = MakeShareable(new FUICommandList);

	CommandList->MapAction(
		FFoolishGameCommands::Get().GenerateTables, FExecuteAction::CreateLambda([]
		{
			FMenuAction_GenerateTables().GenerateTables();
		}), FCanExecuteAction());
	CommandList->MapAction(
		FFoolishGameCommands::Get().FrameworkSettings, FExecuteAction::CreateLambda([]
		{
			if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
			{
				SettingsModule->ShowViewer(TEXT("Project"), TEXT("Foolish Game"), TEXT("Framework"));
			}
		}), FCanExecuteAction());
	CommandList->MapAction(
		FFoolishGameCommands::Get().FoolishGameEditor, FExecuteAction::CreateLambda([]
		{
			if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
			{
				SettingsModule->ShowViewer(TEXT("Project"), TEXT("Foolish Game"),TEXT("Foolish Game Editor"));
			}
		}), FCanExecuteAction());

	// if (IPluginManager::Get().FindPlugin("WorldCreator"))
	// {
	CommandList->MapAction(
		FFoolishGameCommands::Get().WorldCreatorSettings, FExecuteAction::CreateLambda([]
		{
			if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
			{
				SettingsModule->ShowViewer(TEXT("Project"), TEXT("Foolish Game"),TEXT("World Creator"));
			}
		}), FCanExecuteAction());

	CommandList->MapAction(
		FFoolishGameCommands::Get().OpenPuzzleGeneratorWindow, FExecuteAction::CreateLambda([]
		{
			FGlobalTabmanager::Get()->TryInvokeTab(FName("Puzzle Generator"));
		}), FCanExecuteAction());
	//}

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FFoolishGameToolbar::RegisterMenus));
}

void FFoolishGameToolbar::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FFoolishGameStyle::Shutdown();

	FFoolishGameCommands::Unregister();
}

TSharedRef<SWidget> FFoolishGameToolbar::CreateMenu()
{
	const FFoolishGameCommands& Commands = FFoolishGameCommands::Get();
	FMenuBuilder MenuBuilder(true, CommandList);
	MenuBuilder.BeginSection(NAME_None, FText::FromString(TEXT("Table")));
	MenuBuilder.AddMenuEntry(Commands.GenerateTables,
	                         NAME_None,
	                         FText::FromString(TEXT("Generate")),
	                         FText::FromString(TEXT("Generate")),
	                         FSlateIcon(TEXT("FoolishGameStyle"), TEXT("FoolishGameEditor.GenerateTables"))
	);
	MenuBuilder.EndSection();
	if (IPluginManager::Get().FindPlugin("WorldCreator").IsValid())
	{
		//SubMenuBuilder.AddSeparator();
		MenuBuilder.BeginSection(NAME_None, FText::FromString(TEXT("World Creator")));
		MenuBuilder.AddMenuEntry(Commands.OpenPuzzleGeneratorWindow, NAME_None,
		                         FText::FromString(TEXT("Puzzle Generator")),
		                         FText::FromString(TEXT("Create Puzzles")),
		                         FSlateIcon(
			                         TEXT("WorldCreatorStyle"),
			                         TEXT("WorldCreatorEditor.ToolbarLogo"))
		);
		MenuBuilder.EndSection();
	}
	MenuBuilder.BeginSection(NAME_None, FText::FromString(TEXT("Help")));
	MenuBuilder.AddSubMenu(FText::FromString(TEXT("Settings")),
	                       FText::FromString(TEXT("Settings")),
	                       FNewMenuDelegate::CreateLambda([Commands](FMenuBuilder& SubMenuBuilder)
	                       {
		                       SubMenuBuilder.AddMenuEntry(Commands.FrameworkSettings, NAME_None,
		                                                   FText::FromString(TEXT("Framework")),
		                                                   FText::FromString(TEXT("Framework Settings")),
		                                                   FSlateIcon(
			                                                   TEXT("FoolishGameStyle"),
			                                                   TEXT("FoolishGameEditor.FrameworkSettings"))
		                       );
		                       // TArray<TSharedRef<IPlugin>> Plugins = IPluginManager::Get().GetEnabledPlugins();
		                       // bool bWorldEditorExists = false;
		                       // for (const TSharedRef<IPlugin>& Plugin : Plugins)
		                       // {
		                       //  if (Plugin->GetName() == TEXT("WorldCreator"))
		                       //  {
		                       //   bWorldEditorExists = true;
		                       //  }
		                       // }
		                       if (IPluginManager::Get().FindPlugin("WorldCreator").IsValid())
		                       {
			                       //SubMenuBuilder.AddSeparator();
			                       SubMenuBuilder.AddMenuEntry(Commands.WorldCreatorSettings, NAME_None,
			                                                   FText::FromString(TEXT("World Creator")),
			                                                   FText::FromString(TEXT("World Creator Settings")),
			                                                   FSlateIcon(
				                                                   TEXT("WorldCreatorStyle"),
				                                                   TEXT("WorldCreatorEditor.ToolbarLogo"))
			                       );
		                       }
		                       SubMenuBuilder.AddSeparator();
		                       SubMenuBuilder.AddMenuEntry(Commands.FoolishGameEditor, NAME_None,
		                                                   FText::FromString(TEXT("Foolish Game Editor")),
		                                                   FText::FromString(TEXT("Foolish Game Editor")),
		                                                   FSlateIcon(
			                                                   TEXT("FoolishGameStyle"),
			                                                   TEXT("FoolishGameEditor.FoolishGameEditor"))
		                       );
	                       }),
	                       false,
	                       FSlateIcon(TEXT("FoolishGameStyle"), TEXT("FoolishGameEditor.Settings")));
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

void FFoolishGameToolbar::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	// {
	// 	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.FoolishGame");
	// 	{
	// 		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
	// 		Section.AddMenuEntryWithCommandList(FFoolishGameCommands::Get().ToolbarAction, PluginCommands);
	// 	}
	// }

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("FoolishGame");
			{
				FToolMenuEntry& Entry = Section.AddEntry(
					FToolMenuEntry::InitComboButton(
						"FoolishGameEditor",
						FUIAction(),
						FOnGetContent::CreateRaw(this, &FFoolishGameToolbar::CreateMenu),
						FText::FromString(TEXT("Foolish Game")),
						FText::FromString(TEXT("Foolish Game")),
						FSlateIcon("FoolishGameStyle", "FoolishGameEditor.ToolbarLogo")
					));
				Entry.SetCommandList(CommandList);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
