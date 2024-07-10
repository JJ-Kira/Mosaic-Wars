#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"

#include "GameFramework/Actor.h"
#include "MosaicPaint.generated.h"

UCLASS()
class MOSAICWARS_API AMosaicPaint : public AActor, public IInteractable
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this actor's properties
	AMosaicPaint();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Highlight(FHitResult HitResult, int PlayerIndex) override;
    
	virtual void EndHighlight(FHitResult HitResult, int PlayerIndex) override;

	virtual void Interact(FColor Color, int PlayerIndex, int InstanceIndex) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Paint")
	FColor PaintColor;

	UFUNCTION(BlueprintCallable)
	void SetColor(FColor Color);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterialInstance;
};
