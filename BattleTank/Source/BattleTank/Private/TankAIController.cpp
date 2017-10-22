// Made by Martins Fridenbergs as part of Udemy course.

#include "TankAIController.h"
#include "TankAimingComponent.h"

#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensureMsgf(PlayerTank && ControlledTank, TEXT("No player or controlled tank!"))) { return; }

	//Fire at player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->Fire();

	//Move towards player
	MoveToActor(PlayerTank,AcceptenceRadius);
	
}
