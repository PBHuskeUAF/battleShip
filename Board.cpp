//this file controls AI functions of
//Ship Placement
//Shooting
//Hit Detection

<<<<<<< HEAD
#include "Board.h"
//#include<vector>
//#include<utility>
=======
//#include "Board.h"
#include<vector>
#include<utility>
>>>>>>> d2ee2f32b38014be70ea1e9da2c3fc2d45a43f35
#include <random> 
#include <functional>
#include <iostream>
#include "Game_Header_List.h"

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
Game_Board::tile_Type Game_Board::check_Tile(int row, int col)
{
	return this->_Board[(row * 10 + col)];
}

/*
void Game_Board::set_Tile(int index, Game_Board::tile_Type value)
{
	_Board[index] = value;
}
*/
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

<<<<<<< HEAD
// ***********************************Functions that update the Board****************************
=======
int gen_orientation()
{
	pair<int, int> rand = gen_random();
	return (rand.first % 2);
}

//checks to make sure the generated shot is not a repetition of old shots
bool Game_Level::valid_Shot(pair<int, int> coord)
{
	int tile = check_Tile(coord.first, coord.second);
	if (tile ==2 || tile ==3) // already used this square before
		return false;
	else
		return true; // empty spot nothing is there
}
>>>>>>> d2ee2f32b38014be70ea1e9da2c3fc2d45a43f35

	//update the board with fleets locations
/*
void Game_Board::ship_to_Board(int row, int col, Ship::ship_Dir orien, int size)
{

	if (orien == Ship::vertical)
	{
		for (int j = 0; j < size; j++)//vertical
		{
		 _Board[((row + j) * 10 + col)] = Game_Board::boat;
		}
	}
	else
	{
		for (int j = 0; j < size; j++)
		{
		_Board[row * 10 + col+j] = Game_Board::boat;
		}
	}
}
*/
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









