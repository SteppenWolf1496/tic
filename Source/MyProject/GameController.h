// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameEnums.h"
/**
 * 
 */
class MYPROJECT_API GameController
{
//public:
	GameController();
	~GameController();
	GameController* instance = nullptr;
	GameEnums::MyGameState gameState;
	GameEnums::ApplicationState appState;


public:
	GameController* Instance();

	void Update();
};
