// Made by Martins Fridenbergs as part of Udemy course.

#include "TankAIController.h"
#include "Tank.h"

#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank) 
	{
		auto ControlledTank = Cast<ATank>(GetPawn());

		//Fire at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();

		//Move towards player
		MoveToActor(PlayerTank,AcceptenceRadius);
	}
	
}
