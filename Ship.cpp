// Ship.cpp : Defines the entry point for the console application.

#include "Ship.h"
#include <iostream>
Ship::Ship():_type(carrier), _size(5), _location(pair<int,int>(0,0)),_life(5),_orientation(vertical)
{}

Ship::Ship(ship_Type type, Game_Board & board)
{
	switch (type)
	{
	case carrier:
		_size = 5;
		_life = 5;
		_orientation = gen_Orientation(board);
		_location = place_Ship(board);
		break;
	case battleship:
		_size = 4;
		_life = 4;
		_orientation = gen_Orientation(board);
		_location = place_Ship(board);
		break;
	case cruiser:
		_size = 3;
		_life = 3;
		_orientation = gen_Orientation(board);
		_location = place_Ship(board);
		break;
	case submarine:
		_size = 3;
		_life = 3;
		_orientation = gen_Orientation(board);
		_location = place_Ship(board);
		break;
	case destroyer:
		_size = 2;
		_life = 2;
		_orientation = gen_Orientation(board);
		_location = place_Ship(board);
		break;
	}

}

Ship::ship_Dir Ship::get_Orientation()
{
	return _orientation;
}
void Ship::set_Orientation(ship_Dir orient)
{
	_orientation = orient;
}

pair<int, int> Ship::get_Location()
{
	return _location;
}
void Ship::set_Location(pair<int, int> location)
{
	_location = location;
}

int Ship::get_Size()
{
	return _size;
}
void Ship::set_Size(int size)
{
	_size = size;
}

int Ship::get_Life()
{
	return _life;
}
void Ship::set_Life(int life)
{
	 _life = life;
}

//*************************************Ship Placement Functions***************************************

//randomly generates an orientation for a ship
Ship::ship_Dir Ship::gen_Orientation(Game_Board & board)
{
	Ship::ship_Dir orien;
	pair<int, int> rand = board.gen_Random();
	if (rand.first % 2)
		return orien = Ship::horizontal;
	else
		return orien = Ship::vertical;
}

//checks to see if ship is in bounds
bool Ship::in_Bounds(int row, int col)
{
	//Find coordinate of far edge of ship
	if (get_Orientation() == Ship::vertical)//vertical
	{
		row += get_Size();
	}
	else
	{
		col += get_Size();
	}
	//check if ship is in bounds
	if (row <10 && row > -1 && col <10 && col > -1)
		return true;
	else
		return false;
}

bool Ship::ship_Overlap(int row, int col, Game_Board & board)
{

	if (get_Orientation() == vertical)
	{
		for (int j = 0; j < _size; j++)//vertical
		{
			Game_Board::tile_Type temp = board.check_Tile((row + j) * 10, col);
			if (temp == Game_Board::boat)
				return false;
		}
	}
	else
	{
		for (int j = 0; j < _size; j++)
		{
			Game_Board::tile_Type temp = board.check_Tile((row * 10), (col + j));
			if (temp == Game_Board::boat)
				return false;
		}
	}
}

//returns the location of the ship
pair <int, int> Ship::place_Ship(Game_Board & board)
{
	pair <int, int> coord;
	//confirm coordinates are in bound and not overlapping previous ships
	while (1)
	{
		coord = board.gen_Random();
		//check if inbounds
		if (in_Bounds(coord.first, coord.second) && !ship_Overlap(coord.first, coord.second, board)) //checks to confirm that coordinate will not result in out of bounds nor overlap
		{
			//valid location so update game_board, break loop and return coordinate
			break;
		}
	}
	return coord;
}

/*

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
*/
