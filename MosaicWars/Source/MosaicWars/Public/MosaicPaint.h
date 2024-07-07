#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MosaicPaint.generated.h"

UCLASS()
class MOSAICWARS_API AMosaicPaint : public AActor
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
	FColor PaintColor;

};
