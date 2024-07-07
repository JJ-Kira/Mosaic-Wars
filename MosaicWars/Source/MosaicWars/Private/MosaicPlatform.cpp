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

	// Populate the Tiles
}

// Called when the game starts or when spawned
void AMosaicPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Handle interaction implementation
void AMosaicPlatform::Highlight(FHitResult HitResult)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleInteraction called on MosaicPlatform!"));

	// Check if we hit an instanced static mesh
	UInstancedStaticMeshComponent* ISMComponent = Cast<UInstancedStaticMeshComponent>(HitResult.Component);
	if (ISMComponent)
	{
		int32 InstanceIndex = HitResult.Item;
            
		UE_LOG(LogTemp, Log, TEXT("Hit Instanced Static Mesh Component: %s at Index: %d"), *ISMComponent->GetName(), InstanceIndex);

		ISMComponent->SetCustomDataValue(InstanceIndex, 0, true);

		//TODO: Set 
	}
}
