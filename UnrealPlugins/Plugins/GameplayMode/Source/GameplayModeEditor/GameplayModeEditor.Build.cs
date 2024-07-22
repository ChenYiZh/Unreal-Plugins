// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class GameplayModeEditor : ModuleRules
{
	public GameplayModeEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Framework",
				"FoolishGames",
				"GameplayMode",
				"FrameworkEditor"
				// ... add other public dependencies that you statically link with here ...
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"EditorFramework",
				"UnrealEd",
				"ToolMenus",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"AssetTools",
				"Json",
				"JsonUtilities",
				"AssetRegistry",
				"BlueprintGraph",
				// ... add private dependencies that you statically link with here ...	
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		//PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));
		if (Target.bBuildEditor)
		{
			//PRAGMA_DISABLE_OPTIMIZATION
			//PRAGMA_ENABLE_OPTIMIZATION
			OptimizeCode = CodeOptimization.Never;
		}

		bEnableExceptions = true;
	}
}