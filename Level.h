#pragma once
#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include "Board.h"
class Game_Level
{
private:
	int _Number_of_Tiles; // a battleship game is a 10x10 board
	Game_Board _battle_Board;
public:
	//Constructor
	Game_Level();//makes a basic empty board

				 // ******************************member Functions********************************************
				 //calls the constructor of the Ship class in order to make ships
	void generate_Ships();
};
#endif // !LEVEL_H_INCLUDED