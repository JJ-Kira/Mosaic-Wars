#include "MosaicPlatform.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AMosaicPlatform::AMosaicPlatform()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create the instanced static mesh component and attach it to the root
	Tiles = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Tiles"));
	RootComponent = Tiles;

	// Initialize platform size
	PlatformSize = 0;

	// Initialize OwningPlayer to -1
	OwningPlayer = -1;

	BaseColor = FColor::Black;
	EdgeBaseColor = FColor::White;
	EdgeHighlightColor = FColor::Red;
}

// Called when the game starts or when spawned
void AMosaicPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Handle interaction implementation
void AMosaicPlatform::Highlight(FHitResult HitResult, int PlayerIndex)
{
		if (Tiles && OwningPlayer == PlayerIndex)
	{
		//UE_LOG(LogTemp, Log, TEXT("Hit Instanced Static Mesh Component: %s at Index: %d"), *Tiles->GetName(), InstanceIndex);
		int32 InstanceIndex = HitResult.Item;
			
		Tiles->SetCustomDataValue(InstanceIndex, 3, EdgeHighlightColor.R);
		Tiles->SetCustomDataValue(InstanceIndex, 4, EdgeHighlightColor.G);
		Tiles->SetCustomDataValue(InstanceIndex, 5, EdgeHighlightColor.B, true);;
	}
}

void AMosaicPlatform::EndHighlight(FHitResult HitResult, int PlayerIndex)
{
	if (Tiles && OwningPlayer == PlayerIndex)
	{
		int32 InstanceIndex = HitResult.Item;
		
		Tiles->SetCustomDataValue(InstanceIndex, 3, EdgeBaseColor.R);
		Tiles->SetCustomDataValue(InstanceIndex, 4, EdgeBaseColor.G);
		Tiles->SetCustomDataValue(InstanceIndex, 5, EdgeBaseColor.B, true);
	}
}

void AMosaicPlatform::Interact(FColor Color, int PlayerIndex, int InstanceIndex)
{
	if (Tiles && OwningPlayer == PlayerIndex)
	{
		Mosaic[InstanceIndex] = Color;
		Tiles->SetCustomDataValue(InstanceIndex, 0, Color.R);
		Tiles->SetCustomDataValue(InstanceIndex, 1, Color.G);
		Tiles->SetCustomDataValue(InstanceIndex, 2, Color.B, true);
	}
}

#if WITH_EDITOR
void AMosaicPlatform::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	// Check if the property being changed is the NumberOfRounds
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AMosaicPlatform, PlatformSize))
	{
		// Adjust the size of NumberOfColorsPerRound to match NumberOfRounds
		Mosaic.SetNum(PlatformSize * PlatformSize);
	}
}
#endif