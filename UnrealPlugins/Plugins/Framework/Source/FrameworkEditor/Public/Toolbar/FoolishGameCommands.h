// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FoolishGameStyle.h"
#include "Framework/Commands/Commands.h"


/** Framework的编辑器菜单按钮 */
class FFoolishGameCommands : public TCommands<FFoolishGameCommands>
{
public:
	FFoolishGameCommands():
		TCommands<FFoolishGameCommands>(TEXT("FrameworkEditor"),
		                                NSLOCTEXT("Contexts", "FrameworkEditor", "Framework Editor"),
		                                NAME_None,
		                                FFoolishGameStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	/** 主菜单消息 */
	TSharedPtr<FUICommandInfo> ToolbarAction;
	/** 创建表格 */
	TSharedPtr<FUICommandInfo> GenerateTables;
	/** 框架的配置信息 */
	TSharedPtr<FUICommandInfo> FrameworkSettings;
	/** 编辑器配置 */
	TSharedPtr<FUICommandInfo> FoolishGameEditor;
	/** 世界创建的设置配置 */
	TSharedPtr<FUICommandInfo> WorldCreatorSettings;


	/** 模块地图生成面板 */
	TSharedPtr<FUICommandInfo> OpenPuzzleGeneratorWindow;
};
