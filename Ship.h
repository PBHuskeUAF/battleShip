#ifndef  SHIP_H_INCLUDED
#define SHIP_H_INCLUDED
#include<vector>
#include<utility>
#include <random> 
#include <functional>
#include <SFML\Graphics.hpp>
using std::pair;
using std::vector;
#include "Board.h"


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

	Ship(ship_Type type, const int * _game_Board);
	
	
	Ship(ship_Type type, int orientation, const int * _game_Board);

	//member functions
	//bool is_Destroyed();
	//bool is_Hit(int r, int col);

	void set_orientation(int orient);

	int getOrientation();

	pair<int, int> getLocation();

	int getSize();
//checks to see if ship is in bounds
	bool in_Bounds(int row, int col);

	bool ship_Overlap(int row, int col, const int * _game_Board);

//returns the location of the ship
	pair <int, int> place_Ship(const int * _game_Board);

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
