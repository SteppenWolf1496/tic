// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MyProject.h"
#include "MyProjectBlock.h"
#include "MyProjectBlockGrid.h"
#include "GameController.h"

std::vector<AMyProjectBlock*> AMyProjectBlock::A_Blocks;
int AMyProjectBlock::crossMatrix[9] = { 1,0,1,0,1,0,1,0,1 };
int AMyProjectBlock::zeroMatrix[9] = { 1,1,1,1,0,1,1,1,1 };


void AMyProjectBlock::MakeZero()
{
	for (int i = 0; i < 9; ++i) {
		if (!zeroMatrix[i])
		{
			subBlocks[i]->SetActorHiddenInGame(true);
		}
		else {
			subBlocks[i]->BlockMesh->SetMaterial(0,subBlocks[i]->MZero);
		}
		
	}
}



void AMyProjectBlock::MakeCross()
{
	for (int i = 0; i < 9; ++i) {
		if (!crossMatrix[i])
		{
			subBlocks[i]->SetActorHiddenInGame(true);
		}
		else {
			subBlocks[i]->BlockMesh->SetMaterial(0, subBlocks[i]->MCross);
		}
	}
}

void AMyProjectBlock::Reset()
{

	myState = GameEnums::BlockState::Empty;
}

void AMyProjectBlock::SetBlockState(GameEnums::BlockState _state)
{
	myState = _state;
}

GameEnums::BlockState AMyProjectBlock::GetBlockState()
{
	return myState;
}




AMyProjectBlock::AMyProjectBlock()
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> BlueMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> OrangeMaterial;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/Assets/Meshes/SM_Cell.SM_Cell"))
			, BlueMaterial(TEXT("/Game/Puzzle/Meshes/BlueMaterial.BlueMaterial"))
			, OrangeMaterial(TEXT("/Game/Puzzle/Meshes/OrangeMaterial.OrangeMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
	StartMaterial = ConstructorStatics.BlueMaterial.Get();
	// Create static mesh component
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());
	//BlockMesh->SetRelativeScale3D(FVector(1.f,1.f,0.25f));
	//BlockMesh->SetRelativeLocation(FVector(0.f,0.f,25.f));
	BlockMesh->SetMaterial(0, StartMaterial);
	BlockMesh->SetupAttachment(DummyRoot);
	BlockMesh->OnClicked.AddDynamic(this, &AMyProjectBlock::BlockClicked);
	BlockMesh->OnInputTouchBegin.AddDynamic(this, &AMyProjectBlock::OnFingerPressedBlock);
	//BlockMesh->bVisible = false;
	// Save a pointer to the orange material
	OrangeMaterial = ConstructorStatics.OrangeMaterial.Get();
	//A_Blocks.add(this);

	A_Blocks.push_back(this);
	myState = GameEnums::BlockState::Empty;
		
}

void AMyProjectBlock::BeginPlay()
{
	Super::BeginPlay();

	ASubBlock* tmpSB;
	float XOffset; // Divide by dimension
	float YOffset; // Modulo gives remainder
	for (int i = 0; i < 9; i++)
	{
		XOffset = (i / 3) * 70 - 70; // Divide by dimension
		YOffset = (i % 3) * 70 - 70; // Modulo gives remainder

								// Make postion vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();
		
		
		tmpSB = GetWorld()->SpawnActor<ASubBlock>(BlockLocation, FRotator(0, 0, 0));
		tmpSB->Num = i;
		subBlocks[i] = tmpSB;
		//GetWorld()->spaw
		//tmpSMC->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());

	}

}

void AMyProjectBlock::BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{

	if (GameController::Instance()->GetGameState() != GameEnums::MyGameState::PlayerMove) return;

	
	// Check we are not already active
	if(GetBlockState() == GameEnums::BlockState::Empty)
	{
		
		SetBlockState(GameEnums::BlockState::Cross);

		//Draw Cross
		MakeCross();

		// Tell the Grid
		if (OwningGrid != NULL)
		{
			OwningGrid->MakedMove(this);
		}
	}
	
}




int AMyProjectBlock::GetIndexWithMove(int _i, int _move)
{
	return _i - _move;
}


void AMyProjectBlock::OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	BlockClicked(TouchedComponent, EKeys::Invalid);
}
