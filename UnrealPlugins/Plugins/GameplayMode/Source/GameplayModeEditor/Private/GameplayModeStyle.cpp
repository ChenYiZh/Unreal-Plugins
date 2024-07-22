#include "GameplayModeStyle.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FGameplayModeStyle::StyleInstance = nullptr;

void FGameplayModeStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FGameplayModeStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FGameplayModeStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("GameplayModeStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon128x128(128.0f, 128.0f);

TSharedRef<FSlateStyleSet> FGameplayModeStyle::Create()
{
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("GameplayMode")->GetBaseDir() / TEXT("Resources"));
	
	Style->Set("GameplayModeEditor.Strategy", new IMAGE_BRUSH(TEXT("icons/strategy"), Icon128x128));
	Style->Set("GameplayModeEditor.Ability", new IMAGE_BRUSH(TEXT("icons/ability"), Icon128x128));
	Style->Set("GameplayModeEditor.Attributes", new IMAGE_BRUSH(TEXT("icons/attributes"), Icon128x128));
	Style->Set("GameplayModeEditor.GameEffect", new IMAGE_BRUSH(TEXT("icons/game_effect"), Icon128x128));


	return Style;
}

void FGameplayModeStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FGameplayModeStyle::Get()
{
	return *StyleInstance;
}
