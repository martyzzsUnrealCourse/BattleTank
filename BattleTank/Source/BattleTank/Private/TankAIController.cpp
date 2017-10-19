// Made by Martins Fridenbergs as part of Udemy course.

#include "TankAIController.h"
#include "Tank.h"

#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	//Checks if has a possesed tank
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Controlled Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank: %s"), *(ControlledTank->GetName()));
	}

	//Cheks if can find player tank
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NoPlayer Tank Found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	auto PlayerTank = GetPlayerTank();
	if(PlayerTank)
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
