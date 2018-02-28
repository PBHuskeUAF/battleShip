
//This file contains the gameboard and updates its state

#include "Headers/Game_Header_List.h"
#include <random> 
#include <functional>
#include <iostream>

using std::pair;
using std::vector;


//Constructor initializes gameboard with empty tiles
Game_Board::Game_Board(sf::Vector2f m_pos, bool is_human): Object(m_pos)
{
	//Initialize Game Board
	_Board = new tile_Type[Number_of_Tiles];

	//An int value of zero corresponds to an empty space
	for (int i = 0; i < Number_of_Tiles; i++)
	{
		_Board[i] = Game_Board::empty;
		m_is_hit[i] = false;
		m_is_miss[i] = false;
		m_to_be_drawn[i] = false;
	}

	board_visible = false;

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

	m_temp_rect_shape.setSize(sf::Vector2f(50.f, 50.f));
	//m_temp_rect_shape.setFillColor(sf::Color::Red);
	m_temp_rect_shape.setTexture(&m_temp_board_texture);


	//3 ships, sizes 3,4, and 5
	if (!is_human)
	{
		ship3 = new Ship(Ship::cruiser, *this);
		ship1 = new Ship(Ship::battleship, *this);
		ship2 = new Ship(Ship::carrier, *this);
		ship5 = new Ship(Ship::submarine, *this);
		ship4 = new Ship(Ship::destroyer, *this);
	}
	else
	{
		ship3 = new Ship(Ship::cruiser);
		ship1 = new Ship(Ship::battleship);
		ship2 = new Ship(Ship::carrier);
		ship5 = new Ship(Ship::submarine);
		ship4 = new Ship(Ship::destroyer);
	}
}
void Game_Board::switchStates(int state, Game & game)
{
	if (state == 1)
	{
		game.change_state(Game::MENU);
	}
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

void Game_Board::set_tile(int row, int col, tile_Type type)
{
	_Board[10 * row + col] = type;
}

float Game_Board::get_tile_size()
{
	return m_temp_rect_shape.getSize().x;//y component is the same
}

bool Game_Board::set_ship(int i,int row, int col, Ship::ship_Dir dir )
{
	if (i == 1)
	{
		return ship1->place_Ship(*this,row, col, dir);
	}
	if (i == 2)
	{
		return ship2->place_Ship(*this, row, col, dir);
	}
	if (i == 3)
	{
		return ship3->place_Ship(*this, row, col, dir);
	}
	if (i == 4)
	{
		return ship4->place_Ship(*this, row, col, dir);
	}
	if (i == 5)
	{
		return ship5->place_Ship(*this, row, col, dir);
	}

}



sf::Vector2i& Game_Board::getClickedTile(Screen & screen)
{
	if (screen.is_mouse_clicked())
	{
		float xpos = screen.get_mouse_position().x - screen.getPosition().x - m_pos.x - 6.8; //Don't ask me why these extra numbers are nessessary,
		float ypos = screen.get_mouse_position().y - screen.getPosition().y - m_pos.y - 30; //I have no idea.
		xpos /= m_temp_rect_shape.getSize().x;
		ypos /= m_temp_rect_shape.getSize().y;

		xpos = std::floor(xpos) + 1;
		ypos = std::floor(ypos) + 1;
		return sf::Vector2i(ypos, xpos); //row then col
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

				if (m_is_hit[10 * (j - 1) + (i - 1)])
				{
					
					m_temp_rect_shape.setFillColor(sf::Color::Red);
				}
				if (m_is_miss[10 * (j - 1) + (i - 1)])
				{
					std::cout << "missed" << std::endl;
					m_temp_rect_shape.setFillColor(sf::Color::Green);
				}
				if (board_visible)
				{
					if (check_Tile(j - 1, i - 1) == Game_Board::tile_Type::boat)
					{
						m_temp_rect_shape.setFillColor(sf::Color::Blue);
					}
				}
				if (m_to_be_drawn[10 * (j - 1) + (i - 1)])
				{
					m_temp_rect_shape.setFillColor(sf::Color::Yellow);
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

void Game_Board::fake_draw(int row, int col, Ship::ship_Dir dir, int ship_size)
{
	for (int i = 0;i < 100;i++)
	{
		m_to_be_drawn[i] = false;
	}


	if (dir == Ship::horizontal)
	{
		for (int i = 0;i < ship_size;i++)
		{
			if (10 * row + col + i >= 100)
			{
				break;
			}
			m_to_be_drawn[10 * row + col + i] = true;
		}
	}
	else
	{
		for (int i = 0;i < ship_size;i++)
		{
			if (10 * (row+i) + col >= 100)
			{
				break;
			}
			m_to_be_drawn[10 * (row+ i) + col] = true;
		}
	}
}

void Game_Board::clear_fake_draw()
{
	for (int i = 0;i < 100;i++)
	{
		m_to_be_drawn[i] = false;
	}
}

void Game_Board::make_board_visible()
{
	board_visible = true;
}

void Game_Board::colorTile(sf::Vector2i & hit)
{
	if ((hit.x <= 0) || (hit.y <= 0) || hit.x > 10 || hit.y > 10)
	{
		return;
	}
	else
	{
		if (check_Tile(hit.x - 1, hit.y - 1) == tile_Type::hit)
		{
			m_is_hit[10 * (hit.x - 1) + (hit.y - 1)] = true;
		}
		else if (check_Tile(hit.x - 1, hit.y - 1) == tile_Type::miss)
		{
			m_is_miss[10 * (hit.x - 1) + (hit.y - 1)] = true;
		}
	}
}
