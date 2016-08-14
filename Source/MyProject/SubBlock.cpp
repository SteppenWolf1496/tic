// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "SubBlock.h"


// Sets default values
ASubBlock::ASubBlock()
{


	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> MainBox;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> IronOreMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> CobbleMaterial;
		FConstructorStatics()
			: MainBox(TEXT("/Game/Assets/Meshes/SM_MCC_Rock.SM_MCC_Rock"))
			, IronOreMaterial(TEXT("/Game/Assets/Materials/M_MCIronOre_Inst.M_MCIronOre_Inst"))
			, CobbleMaterial(TEXT("/Game/Assets/Materials/M_MCCobble_Inst.M_MCCobble_Inst"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
	
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetStaticMesh(ConstructorStatics.MainBox.Get());
	BlockMesh->SetRelativeScale3D(FVector(.7f, .7f, .7f));
	BlockMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//BlockMesh->SetMaterial(0, ConstructorStatics.IronOreMaterial.Get());
	BlockMesh->SetupAttachment(DummyRoot);
	
	MCross = ConstructorStatics.CobbleMaterial.Get();
	MZero = ConstructorStatics.IronOreMaterial.Get();

}



// Called when the game starts or when spawned
void ASubBlock::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASubBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

