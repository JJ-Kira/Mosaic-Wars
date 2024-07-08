#include "MosaicPaint.h"

AMosaicPaint::AMosaicPaint()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMosaicPaint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMosaicPaint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Handle interaction implementation
void AMosaicPaint::Highlight(FHitResult HitResult, int PlayerIndex)
{
	
}

void AMosaicPaint::EndHighlight(FHitResult HitResult, int PlayerIndex)
{
	
}

void AMosaicPaint::Interact(FColor Color, int PlayerIndex, int InstanceIndex)
{
	//TODO: Change mannequin color
}
