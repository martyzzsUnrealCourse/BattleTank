// Made by Martins Fridenbergs as part of Udemy course.

#include "TankMovementComponent.h"
#include "TankTrack.h"

#include "Runtime/Engine/Classes/Engine/World.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack*RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f Intend move forward throw: %f"), Time, Throw);

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//Prevent 2x speed from both inputs
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//Prevent 2x speed from both inputs
}

