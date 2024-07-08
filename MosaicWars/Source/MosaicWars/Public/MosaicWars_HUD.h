#pragma once

#include "CoreMinimal.h"
#include "MosaicPlatform.h"
#include "Blueprint/UserWidget.h"
#include "MosaicWars_HUD.generated.h"

UCLASS()
class MOSAICWARS_API UMosaicWars_HUD : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
    void PerformLineTrace();

    UPROPERTY(EditAnywhere)
    float TraceDistance = 10000.0f; // Adjust the trace distance as needed

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Game")
    int OwningPlayerIndex = -1;
    
    IInteractable* CurrentlyActiveInteractable = nullptr;
    FHitResult CurrentHitResult;
};
