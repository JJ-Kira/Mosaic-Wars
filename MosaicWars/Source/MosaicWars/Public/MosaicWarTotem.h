#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MosaicWarTotem.generated.h"

UCLASS()
class MOSAICWARS_API AMosaicWarTotem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMosaicWarTotem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

private:
	//List of colors from which the mosaic is randomly drawn each round, one for the whole game
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
	TArray<FColor> GameColors;

	//List of how many colors are there in each round
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Colors")
	TArray<int> NumberOfColorsPerRound;

	//Time to paint a single tile (in seconds)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Time")
	float UsePaintTime;

	//Time to get paint from a can (in seconds)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Time")
	float GetPaintTime;

	//Time of a single round (in seconds)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Time")
	float SingleRoundTime;

	//Number of rounds in a single game
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true), Category = "Time")
	int NumberOfRounds;
};
