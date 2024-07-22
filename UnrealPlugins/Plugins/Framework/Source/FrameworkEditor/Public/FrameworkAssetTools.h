#pragma once
/** UFactory注册 */
class FFrameworkAssetTools : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<class FAssetTypeActions_GameRoot> GameRootObjectAction;
	TSharedPtr<class FAssetTypeActions_BlueprintThumbnail> ThumbnailAction;
};
