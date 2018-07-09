// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATankPawn* ATankAIController::GetControlledTank() const {
	return Cast<ATankPawn>(GetPawn());
}

TankPawn* ATankAIController::GetPlayerTank() const {

}

void ATankAIController::BeginPlay(){
	Super::BeginPlay();
	auto PossesedTank = GetControlledTank();
	if (!PossesedTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possesed %s "), *PossesedTank->GetName());
	}
}


