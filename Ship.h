#pragma once
#include<vector>
#include<utility>
using std::pair;
using std::vector;


#include <SFML\Graphics.hpp>


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

/*
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
*/