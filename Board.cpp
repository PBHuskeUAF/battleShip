
//This file contains the gameboard and updates its state

#include "Board.h"
#include <random> 
#include <functional>
#include <iostream>

using std::pair;
using std::vector;

//Constructor initializes gameboard with empty tiles
Game_Board::Game_Board(int Number_of_Tiles)
{
	//Initialize Game Board
	_Board = new tile_Type[Number_of_Tiles];

	//An int value of zero corresponds to an empty space
	for (int i = 0; i < Number_of_Tiles; i++)
	{
		_Board[i] = Game_Board::empty;
	}
}
Game_Board::~Game_Board()
{
	delete _Board;
}
// ******************************Utility Functions**********************************************
const Game_Board::tile_Type * Game_Board::get_Board()
{
	return _Board;
}

//determine what the state of a gameboard tile
//Top left tile (A1) is (0,0). Returns thing in
//(row, col) by returning thing at (row*10 + col).
Game_Board::tile_Type Game_Board::check_Tile(int row, int col)
{
	return this->_Board[(row * 10 + col)];
}

//generates a random number from 0-9 legitimately
pair <int, int> Game_Board::gen_Random()
{
	pair<int, int> coordinates;

	std::random_device rd;
	std::uniform_int_distribution<int> distribution(0, 9);
	std::mt19937 engine(rd()); // Mersenne twister MT19937 
	auto generator = std::bind(distribution, engine);
	int random = generator();  // Generate a uniform integral variate between 0 and 99.


	int row = distribution(engine); // generate random coordinates
	int col = distribution(engine);
	coordinates.first = row;
	coordinates.second = col;
	return coordinates;
}

void Game_Board::update_Board(pair<int, int> coord)
{
	
	Game_Board::tile_Type tile = check_Tile(coord.first, coord.second);
	if (tile == boat)//its a hit
	{
		_Board[coord.first * 10 + coord.second] = hit;
	}
	else//its a miss
	{
		_Board[coord.first * 10 + coord.second] = miss;
	}
}

void Game_Board::set_ship_tile(int row, int col, tile_Type type)
{
	_Board[10 * row + col] = type;
}
