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
	auto PlayerTank = Cast<ATankPawn>(PlayerPawn);
	if (PlayerTank) {
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards the player
		
		auto ControlledTank = Cast<ATankPawn>(GetPawn());

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); //TODO limit firing rate
	}
}
