// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPawn.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPawn* GetControlledTank() const;
	
	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

	//Start the tank to move the barrel towards the target
	void AimTowardsCrosshair();
};
