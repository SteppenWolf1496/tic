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
	static GameController* instance;
	GameEnums::MyGameState gameState;
	GameEnums::ApplicationState appState;


public:
	static GameController* Instance();
	const GameEnums::MyGameState GetGameState();
	void SetGameState(GameEnums::MyGameState _gameState);
	void Update();
};
