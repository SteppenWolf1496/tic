// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
//
#include "GameFramework/Actor.h"
#include <vector>
#include "MyProjectBlock.h"
#include "MyProjectBlockGrid.generated.h"

/** Class used to spawn blocks and manage score */
UCLASS(minimalapi)
class AMyProjectBlockGrid : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** Text component for the score */
	//UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//class UTextRenderComponent* ScoreText;

public:
	AMyProjectBlockGrid();

	/** How many blocks have been clicked */
	int32 Score;

	

	/** Number of blocks along each side of grid */
	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	int32 Size;

	/** Spacing of blocks */
	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	float BlockSpacing;

	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

	static int winlogics[8][3];

	
public:

	/**User make move*/
	void MakedMove(AMyProjectBlock* _block);
	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns ScoreText subobject **/
	//FORCEINLINE class UTextRenderComponent* GetScoreText() const { return ScoreText; }

	std::vector<int> GetIsWin();

	//-1 - player win, 1 - AI Win, 2 - Drow
	int CheckWin();

	std::vector<int> GetBoardDataForAI();
};



