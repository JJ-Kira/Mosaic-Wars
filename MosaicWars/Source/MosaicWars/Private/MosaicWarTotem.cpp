// Fill out your copyright notice in the Description page of Project Settings.


#include "MosaicWarTotem.h"

// Sets default values
AMosaicWarTotem::AMosaicWarTotem(): UsePaintTime(1.5), GetPaintTime(3), SingleRoundTime(60), NumberOfRounds(3)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMosaicWarTotem::BeginPlay()
{
	Super::BeginPlay();
	
}

#if WITH_EDITOR
void AMosaicWarTotem::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	// Check if the property being changed is the NumberOfRounds
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AMosaicWarTotem, NumberOfRounds))
	{
		// Adjust the size of NumberOfColorsPerRound to match NumberOfRounds
		NumberOfColorsPerRound.SetNum(NumberOfRounds);
	}
}
#endif

// Called every frame
void AMosaicWarTotem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NumberOfRounds = 0;
}

