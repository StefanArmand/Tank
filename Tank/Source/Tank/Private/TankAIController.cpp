// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATankPawn* ATankAIController::GetControlledTank() const {
	return Cast<ATankPawn>(GetPawn());
}

ATankPawn* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {	return nullptr; }
	return Cast<ATankPawn>(PlayerPawn);
}

void ATankAIController::BeginPlay(){
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController has not found a player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController has found a player tank called %s "), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire when ready
	}
}
