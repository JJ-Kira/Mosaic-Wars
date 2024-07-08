#pragma once

#include "CoreMinimal.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IInteractable
{
	GENERATED_IINTERFACE_BODY()

public:
	virtual void Highlight(FHitResult HitResult, int PlayerIndex) = 0;

	virtual void EndHighlight(FHitResult HitResult, int PlayerIndex) = 0;

	virtual void Interact(FColor Color, int PlayerIndex, int InstanceIndex) = 0;
};