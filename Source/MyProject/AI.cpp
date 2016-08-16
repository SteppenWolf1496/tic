// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "AI.h"

//win ogics



AI::AI()
{
}

AI::~AI()
{
}


int AI::win(const int _grid[9]) {
	//determines if a player has won, returns 0 otherwise.
	
	unsigned wins[8][3] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 },{ 0,3,6 },{ 1,4,7 },{ 2,5,8 },{ 0,4,8 },{ 2,4,6 } };
	int i;
	for (i = 0; i < 8; ++i) {
		if (_grid[wins[i][0]] != 0 &&
			_grid[wins[i][0]] == _grid[wins[i][1]] &&
			_grid[wins[i][0]] == _grid[wins[i][2]])
			return _grid[wins[i][2]];
	}
	return 0;
}


int AI::minimax(int _grid[9], int player) {
	//How is the position like for player (their turn) on board?
	int winner = win(_grid);
	if (winner != 0) return winner*player;

	int move = -1;
	int score = -2;//Losing moves are preferred to no move
	int i;
	for (i = 0; i < 9; ++i) {//For all moves,
		if (_grid[i] == 0) {//If legal,
			_grid[i] = player;//Try the move
			int thisScore = -minimax(_grid, player*-1);
			if (thisScore > score) {
				score = thisScore;
				move = i;
			}//Pick the one that's worst for the opponent
			_grid[i] = 0;//Reset board after try
		}
	}
	if (move == -1) return 0;
	return score;
}


// 0 1 2
// 3 4 5
// 6 7 8
int AI::MakeMove(int _grid[9])
{
	// first move
	if (_grid[4] == 9) {
		return 4;
	} 

	

	int move = -1;
	int score = -2;
	int i;
	for (i = 0; i < 9; ++i) {
		if (_grid[i] == 0) {
			_grid[i] = 1;
			int tempScore = -minimax(_grid, -1);
			_grid[i] = 0;
			if (tempScore > score) {
				score = tempScore;
				move = i;
			}
		}
	}
	//returns a score based on minimax tree at a given node.
	return move;
}


