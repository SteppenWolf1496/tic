// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Actor.h"
#include "SubBlock.h"
#include "GameEnums.h"
#include <vector>
#include "MyProjectBlock.generated.h"

/** A block that can be clicked */
UCLASS(minimalapi)
class AMyProjectBlock : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BlockMesh;

	UMaterialInstance* StartMaterial;

	
	
	std::vector<ASubBlock*> insideCubes;

	int GetIndexWithMove(int _i, int _move);
	ASubBlock* subBlocks[9];

	static int crossMatrix[9];
	static int zeroMatrix [9];
	
	GameEnums::BlockState myState;

public:
	AMyProjectBlock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	/** Pointer to orange material used on active blocks */
	UPROPERTY()
	class UMaterialInstance* OrangeMaterial;

	/** Grid that owns us */
	UPROPERTY()
	class AMyProjectBlockGrid* OwningGrid;

	/** Handle the block being clicked */
	UFUNCTION()
	void BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	/** Handle the block being touched  */
	UFUNCTION()
	void OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	static std::vector<AMyProjectBlock*> A_Blocks;
	
	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns BlockMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetBlockMesh() const { return BlockMesh; }


	void MakeZero();
	void MakeCross();

	void Reset();

	void SetBlockState(GameEnums::BlockState _state);

	GameEnums::BlockState GetBlockState();
};



