#pragma once
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//knows the board 

//currently runs the AI


#include<vector>
using std::vector;
#include<utility>
#include <random> 
#include <functional>
#include<vector>
using std::pair;
using std::vector;

int Number_of_Tiles = 100;
class Game_Level
{
private:
	int * game_Board;

public:

	//Constructor
	Game_Level();

	//member Functions


	//determine what is in the tile
	int check_Tile(int row, int col);

	//generates a random board coordinate 0-99
	pair <int, int> gen_random();

	//checks to ensure that a shot is not repeated
	bool valid_Shot(pair<int, int> coord);
	//finds the coordinate for the next shot to be made
	pair<int, int>  make_Shot();

	//checks to ensure that ship will be in bounds
	//bool in_Bounds(int row, int col);

	//returns the coordinates of the ship
	//pair <int, int> place_Ship();
};
#endif // !BOARD_H_INCLUDED