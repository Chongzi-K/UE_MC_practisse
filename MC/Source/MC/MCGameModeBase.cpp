// Copyright Epic Games, Inc. All Rights Reserved.


#include "MCGameModeBase.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "Math/Vector2D.h"
#include "Chunk.h"

AMCGameModeBase::AMCGameModeBase()
{
	ChunkRange = RenderingRange / ChunkSize;
}

void AMCGameModeBase::BeginPlay()
{
	Super::BeginPlay();

}

void AMCGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateLocation();

}

void AMCGameModeBase::UpdateLocation()
{
	if (Pawn)
	{
		PawnLocation = Pawn->GetActorLocation();
		PawnLocation2D = FVector2D(PawnLocation.X, PawnLocation.Y);
		if (!(PawnLocation2D.Equals(ChunkLocation,100)))
		{
			UE_LOG(LogTemp, Warning, TEXT("Call AddChunk"));
			//玩家已经偏移上一次chunklocation，更新玩家所在的chunklocation
			ChunkLocation = PawnLocation2D;
			PlayerChunkIndex = FVector2D(int32(ChunkLocation.X / ChunkSize), int32(ChunkLocation.Y / ChunkSize));
			AddChunk();
		}

	}
}

void AMCGameModeBase::AddChunk()
{
	for (int32 k = PlayerChunkIndex.X - ChunkRange; k < PlayerChunkIndex.X + ChunkRange; k++)
	{
		for (int32 i = PlayerChunkIndex.Y - ChunkRange; i < PlayerChunkIndex.Y + ChunkRange;i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d,%d"), k, i);
			if (Chunk)
			{
				FVector Location = FVector(k * ChunkSize, i * ChunkSize, 0.0f);
				SpawnChunkEvent(Chunk, Location,FVector2D(k,i));
				UE_LOG(LogTemp, Warning, TEXT("Call SpawnChunkEvent"))
			}
		}
	}

}
void AMCGameModeBase::SpawnChunk(UClass* ToSpawn, const FVector& Location)
{
	UE_LOG(LogTemp, Warning, TEXT("Call SpawnChunk"));

	UWorld* World = GetWorld();
	FActorSpawnParameters SpawnParams;
	if (World&&ToSpawn)
	{
		World->SpawnActor<AActor>(ToSpawn, Location, FRotator(0.0f));
	}
	
}

FVector2D AMCGameModeBase::AddChunkX(bool N)
{
	//int32 ChunkRange = RenderingRange / ChunkSize;
	

	return FVector2D(ChunkLocation.X + ChunkRange,ChunkLocation.X - ChunkRange);
}

FVector2D AMCGameModeBase::AddChunkY(bool N)
{
	//int32 ChunkRange = RenderingRange / ChunkSize;


	return FVector2D(ChunkLocation.Y + ChunkRange, ChunkLocation.Y - ChunkRange);
}

void AMCGameModeBase::RemoveChunk()
{

}
