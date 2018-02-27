#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//knows the board 
//Generates a basic Board for the AI player
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include<utility>
#include <random> 
#include <functional>
#include <vector>
#include "Object.h"
using std::pair;

class Ship;



class Game_Board : public Object
{

public:
	static const int Number_of_Tiles = 100;
	enum tile_Type { empty = 0, boat, miss, hit };

private:
	tile_Type * _Board;
public:
	Game_Board(sf::Vector2f m_pos);
	~Game_Board();
	tile_Type check_Tile(int row, int col); //determine what is in the tile
	//	void set_Tile(int index, tile_Type value);

	//tile_Type check_Tile(int index);
	pair <int, int> gen_Random();
	//send out the state of the game_board 
	const tile_Type * get_Board();
	void update_Board(pair<int, int> coordinate);
	void set_ship_tile(int row, int col, tile_Type type);

	sf::Vector2i& getClickedTile(Screen & screen);
	void colorTile(sf::Vector2i &);
	void render(Screen & screen);


private:
	sf::Font m_font;
	sf::Texture m_temp_board_texture;
	sf::RectangleShape m_temp_rect_shape;
	bool m_is_hit[100];
	Ship* ship1;
	Ship* ship2;
	Ship* ship3;
};
#endif // !BOARD_H_INCLUDED
