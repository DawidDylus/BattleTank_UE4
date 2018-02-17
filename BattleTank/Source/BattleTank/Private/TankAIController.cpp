// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
		
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is possesing: %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank is not found"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is a PlayerTank"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}