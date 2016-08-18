// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "GameController.h"
#include "AI.h"

GameController* GameController::instance = nullptr;

GameController::GameController()
{
	appState = GameEnums::ApplicationState::InGame;
	gameState = GameEnums::MyGameState::PlayerMove;
}

GameController::~GameController()
{
}

GameController * GameController::Instance()
{
	if (instance == nullptr) instance = new GameController();
	return instance;
}

GameEnums::MyGameState GameController::GetGameState()
{
	return gameState;
}

void GameController::SetGameState(GameEnums::MyGameState _gameState)
{
	gameState = _gameState;
}

void GameController::Update()
{
	if (appState == GameEnums::ApplicationState::InGame) {

		if (gameState == GameEnums::MyGameState::AIMove) {
			
		}
	}


}
