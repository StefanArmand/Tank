// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPawn.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay(){
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto GetPlayerTank = Cast<ATankPawn>(PlayerPawn);
	if (GetPlayerTank) {
		// TODO Move towards the player

		// Aim towards the player
		
		auto GetControlledTank = Cast<ATankPawn>(GetPawn());

		GetControlledTank->AimAt(GetPlayerTank->GetActorLocation());

		GetControlledTank->Fire(); //TODO limit firing rate
	}
}
