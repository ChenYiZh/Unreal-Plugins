// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameRoot.h"
#include "UObject/NoExportTypes.h"
#include "FrameworkSettings.generated.h"

/**
 * 
 */
UCLASS(config=FrameworkSettings, defaultconfig, meta=(DisplayName="Framework"))
class FRAMEWORK_API UFrameworkSettings : public UObject
{
	GENERATED_BODY()

public:
	/** 全局类 */
	UPROPERTY(config, NoClear, EditAnywhere, Category="Configs",
		meta=(DisplayThumbnail="true", MetaClass="/Script/Framework.GameRoot"))
	FSoftClassPath GameRoot;
	/** 蓝图与C++构建的桥梁 */
	UPROPERTY(config, NoClear, EditAnywhere, Category="Configs",
		meta=(DisplayThumbnail="true", MetaClass="/Script/Framework.BlueprintBridgeUtilsBase"))
	FSoftClassPath BlueprintBridgeUtils;
};
