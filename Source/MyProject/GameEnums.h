// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class MYPROJECT_API GameEnums
{
public:

	static enum GameState
	{
		PlayerMove,
		AIMove,
		PlayerWin,
		AIWin,
		JustStarted
	};

	static enum ApplicationState
	{
		Loading = 1,
		AdvReady = 2,
		InGame = 4,
		InStartScreen = 8,
		InCompleteScreen = 16
		
	};

	GameEnums();
	~GameEnums();
};
