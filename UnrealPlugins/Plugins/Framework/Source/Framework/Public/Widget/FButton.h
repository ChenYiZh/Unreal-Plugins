// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "FButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonTappedEvent);

/**
 * 
 */
UCLASS()
class FRAMEWORK_API UFButton : public UButton
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	bool bClearClickEventOnInitialize = true;

public:
	/** Called when the button is tapped, instead of clicked */
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FOnButtonTappedEvent OnTapped;

	UFUNCTION()
	void OnTappedBroadcast() const;

	virtual void OnWidgetRebuilt() override;
	virtual void BeginDestroy() override;
};
