// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Attribute/CharacterAttributeSet.h"

#include "Log/FConsole.h"

bool UCharacterAttributeSet::IsEmptyHealth_Implementation()
{
	UFConsole::WriteWarnWithCategory(TEXT("Attributes"),TEXT("You should override the function: IsEmptyHealth"));
	return true;
}
