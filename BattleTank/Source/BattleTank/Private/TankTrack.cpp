// Made by Martins Fridenbergs as part of Udemy course.

#include "TankTrack.h"

#include "Runtime/Engine/Classes/Engine/World.h"

void UTankTrack::SetThrottle(float Throttle) 
{
	//TODO Clamp throttle values
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}


