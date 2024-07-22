// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Tween/TweenComponent.h"
#include "TweenScaleComponent.generated.h"

/** 如果有父节点则调节父节点，不然调节当前节点 */
UCLASS(Blueprintable, BlueprintType,
	HideCategories=(Mobility, Sockets, Cooking, Physics, LOD, Collision),
	ClassGroup=(Tween), meta=(BlueprintSpawnableComponent))
class FRAMEWORK_API UTweenScaleComponent : public UTweenComponent
{
	GENERATED_BODY()

protected:
	virtual void Play_Implementation(USceneComponent* Component, float Alpha) override;

#pragma region Variables

public:
	/** 是否使用世界坐标 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tween")
	bool bGlobal = false;
	/** 起始坐标 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tween")
	FVector From = FVector(1, 1, 1);
	/** 终点坐标 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tween")
	FVector To = FVector(1, 1, 1);

#pragma endregion
};
