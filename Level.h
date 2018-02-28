#pragma once
#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include "Board.h"
#include "Ship.h"
#include<vector>
#include<memory>
using std::vector;
class Game_Board;

class Game_Level
{
private:
	int _Number_of_Tiles; // a battleship game is a 10x10 board
						  //Game_Board * _battle_Board;

	vector < std::unique_ptr<Ship> > _fleet;
public:
	//Constructor
	Game_Level();//makes a basic empty board
	Game_Board * _battle_Board;
	// ******************************member Functions********************************************
	//calls the constructor of the Ship class in order to make ships
	void generate_Ships();
	vector<int> generate_Ship_Location_Array(int row, int col, int size, Ship::ship_Dir orien);
	void update_Board(const vector<int> & boat);

	//Game_Board * get_Board();
	int get_Board_Length();
};
#endif // !LEVEL_H_INCLUDED