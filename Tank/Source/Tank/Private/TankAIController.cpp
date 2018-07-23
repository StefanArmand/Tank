// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay(){
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerPawn)) { return; }
	// TODO Move towards the player
	MoveToActor(PlayerPawn, AcceptanceRadius);

	// Aim towards the player

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerPawn->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Aiming) {
		AimingComponent->Fire(); //TODO limit firing rate
	}
	
}
