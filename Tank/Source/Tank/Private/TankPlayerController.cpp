// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

#define OUT

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return;  }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation;
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation) {
		AimingComponent->AimAt(HitLocation);
	}
	// Get world location of linetrace through crosshair
	// if it hits the landscape
		//tell controllet tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraWorldLocation; // To be discarded

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel( HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)) 
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; //line trace didn't succeed
}

// needed for player death
void ATankPlayerController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATankPawn>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
	}
}

void ATankPlayerController::OnPossessedTankDeath() {
	StartSpectatingOnly();
}