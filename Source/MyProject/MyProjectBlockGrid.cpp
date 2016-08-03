// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MyProject.h"
#include "MyProjectBlockGrid.h"
#include "MyProjectBlock.h"

#include "Components/TextRenderComponent.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"


AMyProjectBlockGrid::AMyProjectBlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	/*ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);*/

	// Set defaults
	Size = 3;
	BlockSpacing = 300.f;
}


void AMyProjectBlockGrid::BeginPlay()
{
	Super::BeginPlay();
	
	for	(int i=0;i<AMyProjectBlock::A_Blocks.size();++i){
		AMyProjectBlock::A_Blocks[i]->OwningGrid = this;
	}


}


void AMyProjectBlockGrid::AddScore()
{
	// Increment score
	Score++;

	// Update text
	//ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE
