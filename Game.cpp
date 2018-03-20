#include "Headers/Game_Header_List.h"
#include <iostream>


void delay()
{
	sf::Clock clock;
	sf::Time time = sf::seconds(0.f);
	while (true)
	{
		time = clock.getElapsedTime();
		if (time.asSeconds() >= 1.f)
			break;
	}


}

Game::Game()
{
	just_entered = false;
	m_player = true;
	m_game_state = MENU;
	setUp = true;
	//m_game_state = BATTLE;
}

void Game::start()
{
	Game game;
	game.main_loop();
}

void Game::change_state(Game::State new_state)
{
	m_game_state = new_state;
}

bool Game::isWon()
{
	bool flag = true;
	if (!m_player)
	{
		for (int row = 0;row < 10;row++)
		{
			for (int col = 0; col < 10; col++)
			{
				flag &= !(board->check_Tile(row, col) == board->tile_Type::boat);
			}
		}
	}
	else
	{
		for (int row = 0;row < 10;row++)
		{
			for (int col = 0; col < 10; col++)
			{
				flag &= !(board2->check_Tile(row, col) == board2->tile_Type::boat);
			}
		}
	}

	return flag;
}

void Game::main_loop()
{
	int ship_counter = 1;
	int ship_row = 0;
	int ship_col = 0;
	int ship_size = 4;
	Ship::ship_Dir dir = Ship::vertical;

	sf::Time time = sf::seconds(0.f);
	sf::Clock clock;


	Menu* menu = new Menu(sf::Vector2f(m_screen.getWindow().getSize().x/2.f - 125.f, 50.f));
	board = new Game_Board(sf::Vector2f(100.f, 50.f),false);
	board2 = new Game_Board(sf::Vector2f(100.f, 50.f),true);
	board2->make_board_visible();

	Ship_Display* ship1 = new Ship_Display(sf::Vector2f(800.f, 200.f));
	ship1->set_rectangle_size(sf::Vector2f(100.f, 50.f));
	ship1->set_Texture("Res/Ship_Picture.jpg");
	//ship1->flip_orien();


	while (!m_screen.isClosed())
	{
		std::vector<Object *> Objects_to_render;
		sf::Vector2i click;
		pair<int, int> to_move;
		switch (m_game_state)
		{
		case MENU:
			std::cout << "menu" << std::endl;
			Objects_to_render.push_back(menu);
			menu->switchStates((menu->getClickedItem(m_screen)), *this);
			break;
		case BATTLE:
			std::cout << "battle" << std::endl;
			board2->clear_fake_draw();
			if (setUp)
			{
				if (m_screen.isKeyClicked(sf::Keyboard::Up))
				{
					if (ship_row > 0)
						ship_row--;
				}
				if (m_screen.isKeyClicked(sf::Keyboard::Left))
				{
					if (ship_col > 0)
						ship_col--;
				}
				if (m_screen.isKeyClicked(sf::Keyboard::Down))
				{
					if (dir == Ship::vertical)
					{
						if (ship_row + ship_size < 10)
							ship_row++;
					}
					else
					{
						if (ship_row<9)
							ship_row++;
					}

				}
				if (m_screen.isKeyClicked(sf::Keyboard::Right))
				{
					if (dir == Ship::horizontal)
					{
						if (ship_col + ship_size < 10)
							ship_col++;
					}
					else
					{
						if (ship_col<9)
							ship_col++;
					}
				}
				if (m_screen.isKeyClicked(sf::Keyboard::R))
				{
					if (dir == Ship::vertical)
					{
						dir = Ship::horizontal;
						ship_row = 0;
						ship_col = 0;
					}
					else
					{
						ship_row = 0;
						ship_col = 0;
						dir = Ship::vertical;
					}
				}

				if (ship_counter == 1)
				{
					board2->fake_draw(ship_row, ship_col, dir, 4);
					if (m_screen.isKeyClicked(sf::Keyboard::Return))
					{
						if (board2->set_ship(1, ship_row, ship_col, dir))
						{
							ship_counter++;
							ship_row = 0;
							ship_col = 0;
							dir = Ship::vertical;
							ship_size = 3;
						}
					}
				}
				else if (ship_counter == 2)
				{
					board2->fake_draw(ship_row, ship_col, dir, 3);
					if (m_screen.isKeyClicked(sf::Keyboard::Return))
					{
						if (board2->set_ship(2, ship_row, ship_col, dir))
						{
							ship_counter++;
							ship_row = 0;
							ship_col = 0;
							dir = Ship::vertical;
							ship_size = 5;
						}
					}
				}
				else if (ship_counter == 3)
				{
					board2->fake_draw(ship_row, ship_col, dir, 5);
					if (m_screen.isKeyClicked(sf::Keyboard::Return))
					{
						if (board2->set_ship(3, ship_row, ship_col, dir))
						{
							ship_counter++;
							ship_row = 0;
							ship_col = 0;
							dir = Ship::vertical;
							ship_size = 2;
						}
					}
				}
				else if (ship_counter == 4)
				{
					board2->fake_draw(ship_row, ship_col, dir, 2);
					if (m_screen.isKeyClicked(sf::Keyboard::Return))
					{
						if (board2->set_ship(4, ship_row, ship_col, dir))
						{
							ship_counter++;
							ship_row = 0;
							ship_col = 0;
							dir = Ship::vertical;
							ship_size = 3;
						}
					}
				}
				else if (ship_counter == 5)
				{
					board2->fake_draw(ship_row, ship_col, dir, 3);
					if (m_screen.isKeyClicked(sf::Keyboard::Return))
					{
						if (board2->set_ship(5, ship_row, ship_col, dir))
						{
							ship_counter++;
							ship_row = 0;
							ship_col = 0;
							dir = Ship::vertical;
							setUp = false;
						}
					}
				}
				Objects_to_render.push_back(board2);
			}
			else
			{
				//play game
				click = (*board).getClickedTile(m_screen);
				if (m_player)
				{
					//std::cout << "player 1" << std::endl;
					battle_loop(click.x, click.y);
					if (isWon())
					{
						board->switchStates(1, *this);
						//(*board).~Game_Board();
						//(*board2).~Game_Board();
						//board = new Game_Board(sf::Vector2f(100.f, 50.f), false);
						//board2 = new Game_Board(sf::Vector2f(100.f, 50.f), true);
						//board2->make_board_visible();
						just_entered = false;
						//setUp = true;
					}
					Objects_to_render.push_back(board);
					(*board).colorTile(click);
				}
				else
				{
					//std::cout << "Player 2" << std::endl;
					//delay();
					//click = (*board).getClickedTile(m_screen);
					to_move = board2->gen_Random();
					std::cout << to_move.first << "  "<<to_move.second<< std::endl;
					battle_loop(to_move.first, to_move.second);
					if (isWon())
					{
						board->switchStates(1, *this);
						//(*board).~Game_Board();
						//(*board2).~Game_Board();
						//board = new Game_Board(sf::Vector2f(100.f, 50.f), false);
						//board2 = new Game_Board(sf::Vector2f(100.f, 50.f), true);
						//board2->make_board_visible();
						just_entered = false;
						//setUp = true;
					}
					Objects_to_render.push_back(board2);
					(*board2).colorTile(sf::Vector2i(to_move.first,to_move.second));
				}
			}
			break;
		case OPTIONS:
			//update logic
			//draw
			break;
		case EXIT:
			m_screen.close();
			break;
		}
		//handle events
		m_screen.handleEvents();
		m_screen.render(Objects_to_render);
		if (just_entered)
			delay();
	}
}

void Game::battle_loop(int x, int y)
{
	if (x != -1 && y != -1)
	{
		if (m_player)
		{
			if (board->check_Tile(x - 1, y - 1) == board->boat || board->check_Tile(x - 1, y - 1) == board->empty)
			{
				board->update_Board(pair<int, int>(x-1,y-1));
				m_player = false;
				just_entered = true;
				return;
			}
			else
			{
				just_entered = false;
				return;
			}
		}
		else
			if (board2->check_Tile(x - 1, y - 1) == board2->boat || board2->check_Tile(x - 1, y - 1) == board2->empty)
			{
				board2->update_Board(pair<int, int>(x - 1, y - 1));
				just_entered = true;
				m_player = true;
				return;
			}
			else
			{
				just_entered = false;
				return;
			}
	}
	just_entered = false;
}
