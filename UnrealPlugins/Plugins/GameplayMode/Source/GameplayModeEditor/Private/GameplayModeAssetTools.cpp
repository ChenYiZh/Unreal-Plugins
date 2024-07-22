#include "GameplayModeAssetTools.h"

#include "AssetToolsModule.h"
#include "AssetTypeActions_GameplayBlueprintThumbnail.h"
#include "GameplayModeStyle.h"
#include "IAssetTools.h"

void FGameplayModeAssetTools::StartupModule()
{
	FGameplayModeStyle::Initialize();
	FGameplayModeStyle::ReloadTextures();
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	// ThumbnailAction = MakeShareable(new FAssetTypeActions_GameplayBlueprintThumbnail);
	// AssetTools.RegisterAssetTypeActions(ThumbnailAction.ToSharedRef());
}

void FGameplayModeAssetTools::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		AssetTools.UnregisterAssetTypeActions(ThumbnailAction.ToSharedRef());
	}
	FGameplayModeStyle::Shutdown();
}
