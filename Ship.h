#pragma once
#ifndef  SHIP_H_INCLUDED
#define SHIP_H_INCLUDED
#include<vector>
#include<utility>
#include <random> 
#include <functional>
#include <SFML\Graphics.hpp>
using std::pair;
using std::vector;
#include "Board.cpp"


//creates ships and holds their value
class Ship
{
public:
static enum ship_Type { carrier = 0, battleship, cruiser, submarine, destroyer };

private:
	//type of ship
	ship_Type _type;
	//size
	int _size;
	//position row column for one end of the ship
	pair<int, int> _location;
	//life or hits
	int _life;
	//orientation  1 = vertical 0 = horizontal
	int _orientation;

public:
	//constructors
	Ship(ship_Type type, const int & _game_Board)
	{
		switch (type)
		{
		case carrier:
			_size = 5;
			_life = 5;
			_orientation = 1;
			_location = place_Ship(_game_Board);
			break;
		case battleship:
			_size = 4;
			_life = 4;
			_orientation = 1;
			_location = place_Ship(_game_Board);
			break;
		case cruiser:
			_size = 3;
			_life = 3;
			_orientation = 1;
			_location = place_Ship(_game_Board);
			break;
		case submarine:
			_size = 3;
			_life = 3;
			_orientation = 1;
			_location = place_Ship(_game_Board);
			break;
		case destroyer:
			_size = 2;
			_life = 2;
			_orientation = 1;
			_location = place_Ship(_game_Board);
			break;
		}
	}
	
	
	Ship(ship_Type type, int orientation, const int & _game_Board)
	{
		switch (type)
		{
		case carrier:
			_size = 5;
			_life = 5;
			_orientation = orientation;
			_location = place_Ship(_game_Board);
			break;
		case battleship:
			_size = 4;
			_life = 4;
			_orientation = orientation;
			_location = place_Ship(_game_Board);
			break;
		case cruiser:
			_size = 3;
			_life = 3;
			_orientation = orientation;
			_location = place_Ship(_game_Board);
			break;
		case submarine:
			_size = 3;
			_life = 3;
			_orientation = orientation;
			_location = place_Ship(_game_Board);
			break;
		case destroyer:
			_size = 2;
			_life = 2;
			_orientation = orientation;
			_location = place_Ship(_game_Board);
			break;
		}
		
	}

	//member functions
	//bool is_Destroyed();
	//bool is_Hit(int r, int col);

	void set_orientation(int orient)
	{
		_orientation = orient;
	}

	int getOrientation()
	{
		return _orientation;
	}

	pair<int, int> getLocation()
	{
		return _location;
	}

	int getSize()
	{
		return _size;
	}
//checks to see if ship is in bounds
bool in_Bounds(int row, int col)
{

	//Find coordinate of far edge of ship
	if (getOrientation() == 1)//vertical
	{
		row += getSize();
	}
	else
	{
		col += getSize();
	}
	//check if ship is in bounds
	if (row <10 && row > -1 && col <10 && col > -1)
		return true;
	else
		return false;
}

bool ship_Overlap(int row, int col, const int & _game_Board)
{
	
	if (getOrientation())//1 = vertical  0 ==horizontal
	{
		for (int j = 0; j < _size; j++)//vertical
		{
			return _game_Board[(row * 10 + col)];// a value of 1 means a ship is already placed at that tile
			++row;
		}
	}
	else
	{
		for (int j = 0; j < _size; j++)
		{
			return _game_Board[row * 10 + col];
			++col;
		}
	}
}

//returns the location of the ship
pair <int, int> place_Ship(const int & _game_Board)
{
	pair<int, int> coord;

	//create random number generator
	std::random_device rd;
	std::uniform_int_distribution<int> distribution(0, 9);
	std::mt19937 engine(rd()); // Mersenne twister MT19937 
	auto generator = std::bind(distribution, engine);
	int random = generator();  // Generate a uniform integral variate between 0 and 99.

	int row;
	int col;

	//confirm coordinates are in bound and not overlapping previous ships
	while (1)
	{
		row = distribution(engine); // generate random coordinates
		col = distribution(engine);
		//check if inbounds
		if (in_Bounds(row, col) && !ship_Overlap(row, col, _game_Board)) //checks to confirm that coordinate will not result in out of bounds nor overlap
		{
			//if collides with already existing ship

			coord.first = row;
			coord.second = col;
			break;
		}
	}
	return coord;
}

};

class GenericTestShip
{
public:
	enum DIRECTION { VERT, HORIZ };
	GenericTestShip();
	GenericTestShip(int size, DIRECTION dir, std::vector<float>& position);
	void render( sf::RenderWindow&, sf::Vector2f &);
private:
	std::vector<float> m_Position;
	DIRECTION m_dir;
	int m_size;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
};
#endif
