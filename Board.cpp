
//This file contains the gameboard and updates its state

#include "Headers/Game_Header_List.h"
#include <random> 
#include <functional>
#include <iostream>

using std::pair;
using std::vector;


//Constructor initializes gameboard with empty tiles
Game_Board::Game_Board(sf::Vector2f m_pos): Object(m_pos)
{
	//Initialize Game Board
	_Board = new tile_Type[Number_of_Tiles];

	//An int value of zero corresponds to an empty space
	for (int i = 0; i < Number_of_Tiles; i++)
	{
		_Board[i] = Game_Board::empty;
	}


	if (!m_temp_board_texture.loadFromFile("Res/Tile_Ocean.jpg"))
	{
		std::cout << "File not found" << std::endl;
		m_temp_rect_shape.setFillColor(sf::Color::Blue);

	}
	else
		std::cout << "file found" << std::endl;

	if (!m_font.loadFromFile("Res/AdobeArabic-Bold.otf"))
	{
		std::cout << "font not found" << std::endl;
	}
	else
	{
		std::cout << "font found" << std::endl;
	}


	for (int i = 0;i < 100;i++)
	{
		m_is_hit[i] = false;
	}

	m_temp_rect_shape.setSize(sf::Vector2f(50.f, 50.f));
	//m_temp_rect_shape.setFillColor(sf::Color::Red);
	m_temp_rect_shape.setTexture(&m_temp_board_texture);


	//3 ships, sizes 3,4, and 5
	ship1 = new Ship(Ship::battleship, *this);
	ship2 = new Ship(Ship::carrier, *this);
	ship3 = new Ship(Ship::cruiser, *this);
}
Game_Board::~Game_Board()
{
	delete _Board;
}
// ******************************Utility Functions**********************************************
const Game_Board::tile_Type * Game_Board::get_Board()
{
	return _Board;
}

//determine what the state of a gameboard tile
//Top left tile (A1) is (0,0). Returns thing in
//(row, col) by returning thing at (row*10 + col).
Game_Board::tile_Type Game_Board::check_Tile(int row, int col)
{
	return this->_Board[(row * 10 + col)];
}

//generates a random number from 0-9 legitimately
pair <int, int> Game_Board::gen_Random()
{
	pair<int, int> coordinates;

	std::random_device rd;
	std::uniform_int_distribution<int> distribution(0, 9);
	std::mt19937 engine(rd()); // Mersenne twister MT19937 
	auto generator = std::bind(distribution, engine);
	int random = generator();  // Generate a uniform integral variate between 0 and 99.


	int row = distribution(engine); // generate random coordinates
	int col = distribution(engine);
	coordinates.first = row;
	coordinates.second = col;
	return coordinates;
}

void Game_Board::update_Board(pair<int, int> coord)
{
	
	Game_Board::tile_Type tile = check_Tile(coord.first, coord.second);
	if (tile == boat)//its a hit
	{
		_Board[coord.first * 10 + coord.second] = hit;
	}
	else//its a miss
	{
		_Board[coord.first * 10 + coord.second] = miss;
	}
}

void Game_Board::set_ship_tile(int row, int col, tile_Type type)
{
	_Board[10 * row + col] = type;
}



sf::Vector2i& Game_Board::getClickedTile(Screen & screen)
{
	if (screen.is_mouse_pressed())
	{
		float xpos = screen.get_mouse_position().x - screen.getPosition().x - m_pos.x - 6.8; //Don't ask me why these extra numbers are nessessary,
		float ypos = screen.get_mouse_position().y - screen.getPosition().y - m_pos.y - 30; //I have no idea.
		xpos /= m_temp_rect_shape.getSize().x;
		ypos /= m_temp_rect_shape.getSize().y;

		xpos = std::floor(xpos) + 1;
		ypos = std::floor(ypos) + 1;
		return sf::Vector2i(xpos, ypos);
	}
	return sf::Vector2i(-1, -1);
}

void Game_Board::render(Screen & screen)
{


	sf::Text text;
	text.setFont(m_font);

	screen.getWindow().clear(sf::Color::Black);
	//GenericTestShip ship1(3, GenericTestShip::HORIZ, std::vector<float>{1.f, 0.f});
	//GenericTestShip ship2(5, GenericTestShip::VERT, std::vector<float>{5.f, 5.f});
	//GenericTestShip ship3(3, GenericTestShip::HORIZ, std::vector<float>{9.f, 0.f});


	for (int i = 0;i <= 10;i++)
	{
		for (int j = 0;j <= 10;j++)
		{
			if ((j == 0) && (i != 0))
			{
				text.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i - 1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j - 1)) + m_pos.y));
				text.setString(std::to_string(i));
				screen.getWindow().draw(text);
			}
			else if ((j != 0) && (i == 0))
			{
				text.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i - 1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j - 1)) + m_pos.y));
				text.setString((char)(j - 1 + 'a'));
				screen.getWindow().draw(text);
			}
			else if ((j == 0) && (i == 0))
			{
				continue;
			}
			else
			{

				if (m_is_hit[10 * (i - 1) + (j - 1)])
				{
					//m_temp_rect_shape.setFillColor(sf::Color::Green);
				}
				if (check_Tile(i - 1, j - 1) == Game_Board::tile_Type::boat)
				{
					m_temp_rect_shape.setFillColor(sf::Color::Red);
				}

				m_temp_rect_shape.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i - 1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j - 1)) + m_pos.y));
				screen.getWindow().draw(m_temp_rect_shape);
			}
			m_temp_rect_shape.setFillColor(sf::Color::White);

		}
	}
	//ship1.render(window,m_pos);
	//ship2.render(window, m_pos);
	//ship3.render(window, m_pos);

}

void Game_Board::colorTile(sf::Vector2i & hit)
{
	if ((hit.x <= 0) || (hit.y <= 0) || hit.x > 10 || hit.y > 10)
	{
		return;
	}
	else
	{
		m_is_hit[10 * (hit.x - 1) + (hit.y - 1)] = true;
	}
}
