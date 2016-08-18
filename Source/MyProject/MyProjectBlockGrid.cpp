// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MyProject.h"
#include "MyProjectBlockGrid.h"
#include "MyProjectBlock.h"
#include "GameController.h"
#include "GameEnums.h"

#include "Components/TextRenderComponent.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"


// 0 1 2
// 3 4 5
// 6 7 8
int AMyProjectBlockGrid::winlogics[8][3] = { { 0,1,2 }, { 3,4,5 }, { 6,7,8 },
											 { 0,3,6 }, { 1,4,7 }, { 2,5,8 },
											 { 0,4,8 }, { 2,4,6 } };

AMyProjectBlockGrid::AMyProjectBlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	/*
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);
	*/

	// Set defaults
	//Size = 3;
	//BlockSpacing = 300.f;
}


void AMyProjectBlockGrid::BeginPlay()
{
	Super::BeginPlay();
	for	(int i=0;i<AMyProjectBlock::A_Blocks.size();++i){
		AMyProjectBlock::A_Blocks[i]->OwningGrid = this;
	}
}


void AMyProjectBlockGrid::MakedMove(AMyProjectBlock* _block)
{
	if (GameController::Instance()->GetGameState() == GameEnums::MyGameState::PlayerMove) {
		GameController::Instance()->SetGameState = GameEnums::MyGameState::AIMove;


	}
}

std::vector<int> AMyProjectBlockGrid::GetIsWin()
{
	return std::vector<int>();
}

int AMyProjectBlockGrid::CheckWin()
{
	return 0;
}

std::vector<int> AMyProjectBlockGrid::GetBoardDataForAI()
{
	std::vector<int> ret = std::vector<int>(9);
	/*for (int i = 0; i<AMyProjectBlock::A_Blocks.size(); ++i) {
		ret[i] = 
	}*/

	return ret;
}

#undef LOCTEXT_NAMESPACE
