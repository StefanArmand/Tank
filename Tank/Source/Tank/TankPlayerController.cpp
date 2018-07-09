// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATankPawn* ATankPlayerController::GetControlledTank() const {
	return Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto PossesedTank = GetControlledTank();
	if (!PossesedTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesed %s "), *PossesedTank->GetName());
	}
}