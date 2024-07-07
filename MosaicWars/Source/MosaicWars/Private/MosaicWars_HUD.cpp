#include "MosaicWars_HUD.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "MosaicPlatform.h" // Include the header for your interface

void UMosaicWars_HUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    PerformLineTrace();
}

void UMosaicWars_HUD::PerformLineTrace() const
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (!PlayerController) return;

    // Get the viewport size
    int32 ViewportSizeX, ViewportSizeY;
    PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);

    // Get the screen center
    FVector2D ScreenCenter(ViewportSizeX / 2.0f, ViewportSizeY / 2.0f);

    // Convert the screen center to a world direction
    FVector WorldLocation, WorldDirection;
    PlayerController->DeprojectScreenPositionToWorld(ScreenCenter.X, ScreenCenter.Y, WorldLocation, WorldDirection);

    // Define the start and end points for the line trace
    FVector Start = WorldLocation;
    FVector End = Start + (WorldDirection * 1000.0f); // Adjust the trace distance as needed

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(GetWorld()->GetFirstPlayerController()->GetPawn()); // Ignore the player

    if (bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
    {
        DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 1.0f);

        AActor* HitActor = HitResult.GetActor();
        if (HitActor && HitActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
        {
            if (IInteractable* Interface = Cast<IInteractable>(HitActor))
            {
                Interface->Highlight(HitResult);
            }
        }
    }
}
