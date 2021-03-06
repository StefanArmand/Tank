// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "TankAIController.generated.h"

UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:


private:
	//How close can the AI tank get to the player
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();
};
