// Ship.cpp : Defines the entry point for the console application.

#include "Headers/Game_Header_List.h"
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
		//Minus 1, consider a ship of size 1 located at 0,0. 0+1 = 1 suggesting the onlu
		//tile is located at 1, not 0.
		row += get_Size() - 1;
	}
	else
	{
		//Minus 1, consider a ship of size 1 located at 0,0. 0+1 = 1 suggesting the onlu
		//tile is located at 1, not 0.
		col += get_Size() - 1;
	}
	//check if ship is in bounds
	if (row <10 && row > -1 && col <10 && col > -1)
		return true;
	else
		return false;
}

//Returns true if ship overlaps with already placed ship
//Returns false otherwise
bool Ship::ship_Overlap(int row, int col, Game_Board & board)
{

	if (get_Orientation() == vertical)
	{
		for (int j = 0; j < _size; j++)//vertical
		{
			Game_Board::tile_Type temp = board.check_Tile(row + j, col);
			if (temp == Game_Board::boat)
				return true;
		}
	}
	else
	{
		for (int j = 0; j < _size; j++)
		{
			Game_Board::tile_Type temp = board.check_Tile(row , col + j);
			if (temp == Game_Board::boat)
				return true;
		}
	}
	return false;
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
			if (get_Orientation() == horizontal)
			{
				for (int i = 0;i < get_Size();i++)
				{
					board.set_tile(coord.first, coord.second + i, board.boat);
				}
			}
			else
			{
				for (int i = 0;i < get_Size();i++)
				{
					board.set_tile(coord.first + i, coord.second, board.boat);
				}
			}
			//valid location so update game_board, break loop and return coordinate
			break;
		}
	}
	return coord;
}


////////////////////////////////////////////////////////////
// Display stuff                                          //
////////////////////////////////////////////////////////////
void Ship_Display::render( Screen & screen)
{
	screen.getWindow().draw(m_ship_frame);
}

void Ship_Display::set_rectangle_size(sf::Vector2f dim)
{
	m_ship_frame.setSize(dim);
}

void Ship_Display::set_Texture(const char* s)
{
	if (!m_texture.loadFromFile(s))
	{
		std::cout << "File Not found" << std::endl;
	}
	else
	{
		std::cout << "File found" << std::endl;
	}
	m_ship_frame.setTexture(&m_texture);
}

void Ship_Display::flip_orien()
{
	m_ship_frame.rotate(90);
}
