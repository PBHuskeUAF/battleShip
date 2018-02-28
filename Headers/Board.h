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

	Game_Board(sf::Vector2f m_pos);

	//Getters
	const tile_Type * get_Board();
	tile_Type check_Tile(int row, int col);				//allways row 1st, col 2nd
	void set_tile(int row, int col, tile_Type type);	//row 1st col wnd
	float get_tile_size();


	pair <int, int> gen_Random();
	void update_Board(pair<int, int> coordinate);		//row 1st col 2nd

	//Mouse and drawing stuff
	sf::Vector2i& getClickedTile(Screen & screen);
	void colorTile(sf::Vector2i &);						//row 1st col 2nd
	void render(Screen & screen);

	void switchStates(int state, Game &);
	~Game_Board();
private:
	tile_Type * _Board;
	sf::Font m_font;
	sf::Texture m_temp_board_texture;
	sf::RectangleShape m_temp_rect_shape;
	bool m_is_hit[100];
	bool m_is_miss[100];
	Ship* ship1;
	Ship* ship2;
	Ship* ship3;
};
#endif // !BOARD_H_INCLUDED
