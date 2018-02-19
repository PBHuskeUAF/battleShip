#pragma once
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include<vector>
using std::vector;
#include<utility>
#include <random> 
#include <functional>
#include<vector>

int Number_of_Tiles = 100;
class Game_Level
{
private:
	int * game_Board;
	char identifier;

public:
	Game_Level()
	{
		game_Board = new int[Number_of_Tiles];
	}
	int check_Tile(int row, int col)
	{
		return this->game_Board[(row * 10 + col)];
	}

};
#endif // !BOARD_H_INCLUDED