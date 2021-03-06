// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	

public:
	
	virtual void Tick(float DeltaSeconds) override;
	ATank* GetControlledTank() const;

	/*Start the tank moving the barrel so that a shot would hit
	where the crosshair intersect the world*/
	void AimTowardsCrosshair();

private:
	// Return an OUT paramete, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;

	
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 100000.f;
		
};
