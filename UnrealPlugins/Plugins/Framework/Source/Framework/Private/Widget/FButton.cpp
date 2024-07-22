// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/FButton.h"

#include "Systems/InputSystem.h"

void UFButton::OnTappedBroadcast() const
{
	if (UInputSystem::CanTap(this))
	{
		OnTapped.Broadcast();
	}
}

void UFButton::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();
	if (bClearClickEventOnInitialize)
	{
		OnClicked.Clear();
	}
	FScriptDelegate Delegate;
	Delegate.BindUFunction(this, FName("OnTappedBroadcast"));
	OnClicked.Add(Delegate);
}

void UFButton::BeginDestroy()
{
	Super::BeginDestroy();
	OnClicked.Remove(this, FName("OnTappedBroadcast"));
}
