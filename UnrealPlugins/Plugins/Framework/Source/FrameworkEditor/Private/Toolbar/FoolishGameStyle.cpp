#include "Toolbar/FoolishGameStyle.h"
#include "FrameworkEditor.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FFoolishGameStyle::StyleInstance = nullptr;

void FFoolishGameStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FFoolishGameStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FFoolishGameStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("FoolishGameStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon128x128(128.0f, 128.0f);

TSharedRef<FSlateStyleSet> FFoolishGameStyle::Create()
{
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("Framework")->GetBaseDir() / TEXT("Resources"));

	Style->Set("FoolishGameEditor.ToolbarLogo", new IMAGE_BRUSH(TEXT("Icon128"), Icon20x20));
	Style->Set("FoolishGameEditor.GenerateTables", new IMAGE_BRUSH(TEXT("icons/generate_tables"), Icon16x16));

	Style->Set("FoolishGameEditor.Settings", new IMAGE_BRUSH(TEXT("icons/settings"), Icon16x16));
	Style->Set("FoolishGameEditor.FrameworkSettings", new IMAGE_BRUSH(TEXT("icons/framework_settings"), Icon16x16));
	Style->Set("FoolishGameEditor.FoolishGameEditor", new IMAGE_BRUSH(TEXT("icons/foolish_game_editor"), Icon16x16));


	Style->Set("FoolishGameEditor.GameRoot", new IMAGE_BRUSH(TEXT("icons/game_root"), Icon128x128));
	Style->Set("FoolishGameEditor.BlueprintError", new IMAGE_BRUSH(TEXT("icons/blueprint_error"), Icon128x128));
	Style->Set("FoolishGameEditor.GameInstance", new IMAGE_BRUSH(TEXT("icons/game_instance"), Icon128x128));
	Style->Set("FoolishGameEditor.GameDefines", new IMAGE_BRUSH(TEXT("icons/game_defines"), Icon128x128));
	Style->Set("FoolishGameEditor.GameAction", new IMAGE_BRUSH(TEXT("icons/game_action"), Icon128x128));
	Style->Set("FoolishGameEditor.GameEvent", new IMAGE_BRUSH(TEXT("icons/game_event"), Icon128x128));
	Style->Set("FoolishGameEditor.GameSystem", new IMAGE_BRUSH(TEXT("icons/game_system"), Icon128x128));
	Style->Set("FoolishGameEditor.GameScene", new IMAGE_BRUSH(TEXT("icons/game_scene"), Icon128x128));


	return Style;
}

void FFoolishGameStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FFoolishGameStyle::Get()
{
	return *StyleInstance;
}
