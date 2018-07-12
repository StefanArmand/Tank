// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATankPawn;

UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATankPawn * GetControlledTank() const;

	ATankPawn* GetPlayerTank() const;
};
