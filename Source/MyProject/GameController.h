// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class MYPROJECT_API GameController
{
//public:
	GameController();
	~GameController();
	GameController* instance = nullptr;

public:
	GameController* Instance();
};
