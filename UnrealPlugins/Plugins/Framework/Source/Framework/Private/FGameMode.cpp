// Fill out your copyright notice in the Description page of Project Settings.


#include "FGameMode.h"

APawn* AFGameMode::SpawnDefaultPawnAtTransform_Implementation(AController* NewPlayer, const FTransform& SpawnTransform)
{
	APawn* Pawn = Super::SpawnDefaultPawnAtTransform_Implementation(NewPlayer, SpawnTransform);
	Pawn->AddActorLocalOffset(FVector::UpVector * DeltaHeight);
	return Pawn;
}
