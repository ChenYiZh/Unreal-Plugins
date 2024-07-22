#pragma once

#include "CoreMinimal.h"
#include "FrameworkAssetTools.h"
#include "Modules/ModuleManager.h"
#include "Toolbar/FoolishGameToolbar.h"

class FToolBarBuilder;
class FMenuBuilder;

class FFrameworkEditorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void OnPostEngineInit();

public:
	/** 主工具栏 */
	TSharedPtr<FFoolishGameToolbar> FoolishGameToolbar = nullptr;
	/** 右键菜单栏 */
	TSharedPtr<FFrameworkAssetTools> AssetTools = nullptr;
};
