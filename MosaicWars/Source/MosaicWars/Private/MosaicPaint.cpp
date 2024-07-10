#include "MosaicPaint.h"

#include "MosaicWars/MosaicWarsCharacter.h"

AMosaicPaint::AMosaicPaint()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	PaintColor = FColor::White;
}

// Called when the game starts or when spawned
void AMosaicPaint::BeginPlay()
{
	Super::BeginPlay();

	// Create a dynamic material instance from the mesh component's material
	if (MeshComponent->GetMaterial(0))
	{
		DynamicMaterialInstance = UMaterialInstanceDynamic::Create(MeshComponent->GetMaterial(0), this);
		if (DynamicMaterialInstance)
		{
			MeshComponent->SetMaterial(0, DynamicMaterialInstance);
		}
	}
}

// Called every frame
void AMosaicPaint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Handle interaction implementation
void AMosaicPaint::Highlight(FHitResult HitResult, int PlayerIndex)
{
	MeshComponent->CustomDepthStencilValue = 2;
}

void AMosaicPaint::EndHighlight(FHitResult HitResult, int PlayerIndex)
{
	MeshComponent->CustomDepthStencilValue = 0;
}

void AMosaicPaint::Interact(FColor Color, int PlayerIndex, int InstanceIndex)
{
	// Get the player controller
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController) return;
	
	APawn* PlayerPawn = PlayerController->GetPawn();
	if (!PlayerPawn) return;
	
	if (AMosaicWarsCharacter* MosaicWarsCharacter = Cast<AMosaicWarsCharacter>(PlayerPawn))
	{
		MosaicWarsCharacter->ChangeColor(PaintColor);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to cast to AMosaicWarsCharacter"));
	}
}

void AMosaicPaint::SetColor(FColor Color)
{
	MeshComponent->CustomDepthStencilValue = 0;
	FVector ColorVector = FVector(Color.R / 255.0f, Color.G / 255.0f, Color.B / 255.0f);
	DynamicMaterialInstance->SetVectorParameterValue("BaseColor", FLinearColor(ColorVector));
}