// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor2.h"


// Sets default values for this component's properties
UOpenDoor2::UOpenDoor2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor2::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor2::OpenDoor()
{
	AActor* Owner = GetOwner();

	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
}

