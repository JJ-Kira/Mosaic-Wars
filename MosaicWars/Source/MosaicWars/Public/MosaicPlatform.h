#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/Interface.h"
#include "MosaicPlatform.generated.h"

// Interface declaration
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
    GENERATED_BODY()
};

class IInteractable
{
    GENERATED_BODY()

public:
    virtual void Highlight(FHitResult HitResult) = 0;
};

UCLASS()
class MOSAICWARS_API AMosaicPlatform : public AActor, public IInteractable
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    AMosaicPlatform();

    // Interface function implementation
    virtual void Highlight(FHitResult HitResult) override;

    // Owning player controller index
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
    int OwningPlayer;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    // Size of the platform
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Game")
    int32 PlatformSize;

    // Instanced static mesh component to hold the tiles
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Game")
    UInstancedStaticMeshComponent* Tiles;
};
