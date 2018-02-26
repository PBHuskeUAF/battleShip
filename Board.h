#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//knows the board 
//Generates a basic Board for the AI player
#include<utility>
#include <random> 
#include <functional>
#include "Ship.h"
using std::pair;

class Game_Board
{

public:
	static int Number_of_Tiles;
	enum tile_Type { empty = 0, boat, miss, hit };

private:
	tile_Type * _Board;
public:
	Game_Board(int);
	~Game_Board();
	//determine what is in the tile
	tile_Type check_Tile(int row, int col);


	pair <int, int> gen_Random();

	//send out the state of the game_board 
	const tile_Type * get_Board();
	//Place the Ship on the Board
	void ship_to_Board(int row, int col, Ship::ship_Dir orien, int size);
	void update_Board(pair<int, int> coordinate);
};
#endif // !BOARD_H_INCLUDED