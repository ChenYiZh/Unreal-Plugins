// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeviceUtility.generated.h"

/**
 * 
 */
UCLASS()
class FRAMEWORK_API UDeviceUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static bool IsMobile(const UObject* WorldContextObject);
};
