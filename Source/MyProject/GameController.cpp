// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "GameController.h"

GameController::GameController()
{
	
}

GameController::~GameController()
{
}

GameController * GameController::Instance()
{
	if (instance == nullptr) instance = new GameController();
	return instance;
}
