// Made by Martins Fridenbergs as part of Udemy course.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"

//#include "Runtime/Core/Public/Misc/AssertionMacros.h."
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensureMsgf(AimingComponent, TEXT("Aiming component not set!"))) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCroshair();
}

void ATankPlayerController::AimTowardsCroshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensureMsgf(AimingComponent, TEXT("Aiming component not set!"))) { return; }
	
	FVector HitLocation; //Out Parameter
	
	if (GetSightRayHitLocation(HitLocation)) //Has "side effect", is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CroshairXLocation, ViewportSizeY * CroshairYLocation);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirrection;
	if (GetLookDirection(ScreenLocation, LookDirrection)) 
	{
		// Line-trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirrection, HitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirrection) const
{
	FVector CameraWorldLocation;//To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirrection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirrection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirrection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
