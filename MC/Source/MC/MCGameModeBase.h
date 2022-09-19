// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MCGameModeBase.generated.h"






/**
 * 
 */
UCLASS()
class MC_API AMCGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void UpdateLocation();

	UFUNCTION()
	void AddChunk();

	UFUNCTION()
	void SpawnChunk(UClass* ToSpawn, const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnChunkEvent(UClass* ToSpawn, const FVector& Location,const FVector2D ChunkIndex);

	UFUNCTION(BlueprintCallable)
	FVector2D AddChunkX(bool N);

	UFUNCTION(BlueprintCallable)
	FVector2D AddChunkY(bool N);

	UFUNCTION()
	void RemoveChunk();

	UPROPERTY()
	AController* Controller;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	APawn* Pawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector PawnLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector2D PawnLocation2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector2D ChunkLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector2D PlayerChunkIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UClass* Chunk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ChunkRange;



protected:
	AMCGameModeBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 ChunkSize = 1600;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RenderingRange=4800.0f;
};
