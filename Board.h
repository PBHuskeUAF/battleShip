

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
#include <memory>
#include "Ship.h"

class Game_Level
{
private:
	int * _game_Board;

public:
	static int Number_of_Tiles;

	//Constructor
	Game_Level();

	//member Functions


	//determine what is in the tile
	int check_Tile(int row, int col);

	//generates a random board coordinate 0-99
	//pair <int, int> gen_random();

	//checks to ensure that a shot is not repeated
	bool valid_Shot(pair<int, int> coord);
	//finds the coordinate for the next shot to be made
	void make_Shot();
	void update_Board(pair<int, int> coordinate);
	const int * getBoard();
	void ship2Board(std::vector<std::unique_ptr< Ship >> & fleet);

};
#endif // !BOARD_H_INCLUDED