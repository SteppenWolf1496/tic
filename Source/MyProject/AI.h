// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class MYPROJECT_API AI
{
	static int AI::win(const int _grid[9]);
	static int AI::minimax(int _grid[9], int _player);
	
public:
	AI();
	~AI();
	// with type ai use 0 - cross 1 - zero return num of filed where need to set type of movement (zero or cross)
	static int MakeMove(int _grid[9]);
};
