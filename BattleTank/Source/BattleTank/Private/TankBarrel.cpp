// Made by Martins Fridenbergs as part of Udemy course.

#include "TankBarrel.h"

#include "Runtime/Engine/Classes/Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevation,MaxElevation);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}


