// Made by Martins Fridenbergs as part of Udemy course.

#include "Tank.h"

#include "Runtime/Engine/Classes/Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

//auto Time = GetWorld()->GetTimeSeconds();
//UE_LOG(LogTemp, Warning, TEXT("%f:Here!"), Time);

