//this file controls AI functions of
//Ship Placement
//Shooting
//Hit Detection

//#include "Game_Header_List.h"
#include "Board.h"
#include <random> 
#include <functional>
#include <iostream>

using std::pair;
using std::vector;

Game_Board::Game_Board()
{
	//Initialize Game Board
	_Board = new tile_Type[100];

	//An int value of zero corresponds to an empty space
	for (int i = 0; i < 100; i++)
	{
		_Board[i] = Game_Board::empty;
	}
}
//Constructor initializes gameboard with empty tiles
Game_Board::Game_Board(int n)
	: _Board(new tile_Type[n])
{
	for (int i = 0; i < Number_of_Tiles; i++)
	{
		_Board[i] = Game_Board::empty;
	}
}

Game_Board::~Game_Board()
{
	delete[] _Board;
}

Game_Board::Game_Board(const Game_Board & original):_Board(new tile_Type[Number_of_Tiles])
{
	for (int i = 0; i < Number_of_Tiles; i++)
	{
		_Board[i] = original[i];
	}
}

Game_Board & Game_Board::operator=(const Game_Board & original)
{
	Game_Board copy(original);
	std::swap(_Board, copy._Board);
	return *this;
}

// ******************************Utility Functions**********************************************

//determine what the state of a gameboard tile
Game_Board::tile_Type Game_Board::check_Tile(int row, int col)
{
	if ((row * 10 + col) < sizeof(_Board))
		return this->_Board[(row * 10 + col)];
	else
		return Game_Board::miss;
}

const Game_Board::tile_Type & Game_Board::check_Tile(int row, int col) const
{

	if ((row * 10 + col) <sizeof(_Board))
	return this->_Board[(row * 10 + col)];
	else
		return Game_Board::miss;
}

const Game_Board::tile_Type & Game_Board::operator[] (int index) const
{
	if (index < Number_of_Tiles)
		return _Board[index];
	else
		exit(0);
}
 
Game_Board::tile_Type & Game_Board::operator[] (int index)
{
	if (index < Number_of_Tiles)
		return _Board[index];
	else
		exit(0);
}

void Game_Board::set_Tile(int index, Game_Board::tile_Type value)
{
	_Board[index] = value;
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

// ***********************************Functions that update the Board****************************

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









