#pragma once

#include "CoreMinimal.h"
#include "GameplayModeAssetTools.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FGameplayModeEditorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	/** 右键菜单栏 */
	TSharedPtr<FGameplayModeAssetTools> AssetTools = nullptr;
};
