// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond) {
	//find the target to aim towards

	// rotate barrel to that position
	UE_LOG(LogTemp, Warning, TEXT("Barel-Elevate() called at speed %f"), DegreesPerSecond);
}

