//this file controls AI functions of
//Ship Placement
//Shooting
//Hit Detection

#include "ship.h"
#include "Board.h"
#include<vector>
using std::vector;
#include<utility>
#include <random> 
#include <functional>
#include<vector>
using std::pair;
using std::vector;
#include<memory>;


int gen_orientation();


//Constructor
Game_Level::Game_Level()
{
	//Initialize Game Board
	_game_Board = new int[Number_of_Tiles];

	//An int value of zero corresponds to an empty space
	for (int i = 0; i < Number_of_Tiles; i++)
	{
		_game_Board[i] = 0;
	}

	//Call Ships to be generated
	vector < std::unique_ptr<Ship> > fleet;
	vector<int> number_of_ship_Types = {1, 2, 3, 3, 4, 5}; // the number of each ships carrier -> destroyer
	for (int i = 0; i < number_of_ship_Types.size(); i++)
	{
		for (int j = 0; j < number_of_ship_Types[i]; j++)
		{

			fleet.push_back(std::make_unique<Ship>((Ship::ship_Type) i, gen_orientation()));
		}

	}

	//update the board with fleets location and orientation
	for (int i = 0; i < fleet.size(); i++)
	{
		int row = fleet[i]->getLocation().first;
		int col = fleet[i]->getLocation().second;

		if (fleet[i]->getOrientation())//1 = vertical  0 ==horizontal
		{
			for (int j = 0; j < fleet[i]->getSize(); j++)//vertical
			{
				_game_Board[row*10 + col] = 1;
				++row;
			}
		}
		else
		{
			for (int j = 0; j < fleet[i]->getSize(); j++)
			{
				_game_Board[row * 10 + col] = 1;
				++col;
			}
		}


	}


	/*
	Ship Ship(0, gen_orientation()) Carrier;

	Ship Ship(1, gen_orientation()) Battleship1;
	Ship Ship(1, gen_orientation()) Battleship2;

	Ship Ship(2, gen_orientation()) Cruiser1;
	Ship Ship(2, gen_orientation()) Cruiser2;
	Ship Ship(2, gen_orientation()) Cruiser3;

	Ship Ship(3, gen_orientation()) Sub1;
	Ship Ship(3, gen_orientation()) Sub2;
	Ship Ship(3, gen_orientation()) Sub3;
	Ship Ship(3, gen_orientation()) Sub4;

	Ship Ship(4, gen_orientation()) Destroyer1;
	Ship Ship(4, gen_orientation()) Destroyer2;
	Ship Ship(4, gen_orientation()) Destroyer3;
	Ship Ship(4, gen_orientation()) Destroyer4;
	Ship Ship(4, gen_orientation()) Destroyer5;
	*/
	//update Gameboard with ships


}


//generates a random number from 0-9 legitimately
pair <int, int> gen_random()
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

//determine what is in the tile
//0 means empty
//1 = ship
//2 = miss
//3 = hit
int Game_Level::check_Tile(int row, int col)
{
	return this->_game_Board[(row * 10 + col)];
}

//Takes a shot on the board
pair<int, int>  Game_Level::make_Shot()
{
	pair<int, int> coord;
	while (1)
	{
		pair<int, int> attempt = gen_random();
		if (valid_Shot(attempt))
		{
			update_Board(coord);
			coord = attempt;
			break;
		}
	}
	//Need to implement that hash table shifting to closest valid move.
	return coord;
}

void Game_Level::update_Board(pair<int, int> coordinate)
{
	int tile = check_Tile(coord.first, coord.second);
	if (tile == 1)//its a hit
	{
		_game_Board[coord.first * 10 + coord.second] = 3;
	}
	else//its a miss
	{
		_game_Board[coord.first * 10 + coord.second] = 2;
	}
}