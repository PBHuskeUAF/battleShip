// Ship.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "Ship.h"
#include <iostream>
#include<utility>
#include <random> 
#include <functional>
#include<vector>


Ship::Ship(ship_Type type, const int * _game_Board)
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

Ship::Ship(ship_Type type, int orientation, const int * _game_Board)
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

void Ship::set_orientation(int orient)
{
	_orientation = orient;
}

int Ship::getOrientation()
{
	return _orientation;
}

pair<int, int> Ship::getLocation()
{
	return _location;
}

int Ship::getSize()
{
	return _size;
}
//checks to see if ship is in bounds
bool Ship::in_Bounds(int row, int col)
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

bool Ship::ship_Overlap(int row, int col, const int * _game_Board)
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
pair <int, int> Ship::place_Ship(const int * _game_Board)
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



//////////////////////////////////
// Generic Ship class
/////////////////////////////////

GenericTestShip::GenericTestShip()
{
	int m_size = 3;
	m_Position.resize(2);
	m_Position.at(0) = 0;
	m_Position.at(1) = 0;
	m_dir = HORIZ;
	m_shape.setSize(sf::Vector2f(150.f, 50.f));
	m_shape.setPosition(sf::Vector2f(0.f, 0.f));
	m_shape.setFillColor(sf::Color::Red);
}

GenericTestShip::GenericTestShip(int size, DIRECTION dir, std::vector<float>& position)
{
	m_size = size;
	m_dir = dir;
	m_Position = position;

	if (m_dir == HORIZ)
	{
		if ((m_Position.at(1) + m_size - 1) >= 10 || (m_Position.at(1) < 0) || (m_Position.at(0) < 0) || (m_Position.at(0) >= 10))
		{
			m_Position.at(0) = 0;
			m_Position.at(1) = 0;
			m_size = 3;
		}
	}
	else
	{
		if ((m_Position.at(0) + m_size - 1) >= 10 || (m_Position.at(0) < 0) || (m_Position.at(1)<0) || (m_Position.at(1) >= 10))
			{
				m_Position.at(0) = 0;
				m_Position.at(1) = 0;
				m_size = 3;
			}
	}

	if (m_dir == HORIZ)
		 m_shape.setSize(sf::Vector2f((float)50.f*m_size, (float)50.f));
	else
		 m_shape.setSize(sf::Vector2f((float)50.f, (float)m_size*50.f));
	m_shape.setPosition(sf::Vector2f(50.*m_Position.at(1), 50.*m_Position.at(0)));
	m_shape.setFillColor(sf::Color::Red);

}

void GenericTestShip::render(sf::RenderWindow& window, sf::Vector2f & pos)
{
	m_shape.setPosition(sf::Vector2f(50.*m_Position.at(1), 50.*m_Position.at(0)) + pos);
	window.draw(m_shape);
}
