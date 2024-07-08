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
    virtual void Highlight(FHitResult HitResult, int PlayerIndex) = 0;

    virtual void EndHighlight(FHitResult HitResult, int PlayerIndex) = 0;

    virtual void Interact(FColor Color, int PlayerIndex, int InstanceIndex) = 0;
};

UCLASS()
class MOSAICWARS_API AMosaicPlatform : public AActor, public IInteractable
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    AMosaicPlatform();

    // Interface functions implementation
    virtual void Highlight(FHitResult HitResult, int PlayerIndex) override;
    
    virtual void EndHighlight(FHitResult HitResult, int PlayerIndex) override;

    virtual void Interact(FColor Color, int PlayerIndex, int InstanceIndex) override;

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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
    FColor BaseColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
    FColor EdgeBaseColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
    FColor EdgeHighlightColor;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
    TArray<FColor> GameColors;
};
