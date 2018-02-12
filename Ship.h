#pragma once
#include<vector>
#include<utility>
using std::pair;
using std::vector;

class Ship
{

private:
//type of ship
	ship_Type type;
//size
	int size;
//position row column for one end of the ship
	pair<int row, int col>;
//life or hits
	vector<bool> life;
	//orientation  1 = vertical 0 = horizontal
	bool orientation;
public:
	//constructors
	enum ship_Type = { carrier, battleship, cruiser, submarine, destroyer };
	Ship()
	{}
	Ship(ship_Type )
	{}

	//member functions
	bool is_Destroyed();
	bool is_Hit(int r, int col);





};