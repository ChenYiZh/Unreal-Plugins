#include "FrameworkAssetTools.h"

#include "AssetTypeActions_BlueprintThumbnail.h"
#include "IAssetTools.h"
#include "Factory/GameRootFactory.h"

void FFrameworkAssetTools::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
#if 0
	GameRootObjectAction = MakeShareable(new FAssetTypeActions_GameRoot);
	GameRootObjectAction->Category
		= AssetTools.RegisterAdvancedAssetCategory(
			TEXT("Foolish Game"),
			FText::FromString(TEXT("Foolish Game")
			));
	AssetTools.RegisterAssetTypeActions(GameRootObjectAction.ToSharedRef());
#endif
	ThumbnailAction = MakeShareable(new FAssetTypeActions_BlueprintThumbnail);
	AssetTools.RegisterAssetTypeActions(ThumbnailAction.ToSharedRef());
}

void FFrameworkAssetTools::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
#if 0
		AssetTools.UnregisterAssetTypeActions(GameRootObjectAction.ToSharedRef());
#endif
		AssetTools.UnregisterAssetTypeActions(ThumbnailAction.ToSharedRef());
	}
}
