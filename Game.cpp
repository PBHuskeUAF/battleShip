#include "Headers/Game_Header_List.h"
#include <iostream>

Game::Game()
{
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
	Menu* menu = new Menu(sf::Vector2f(m_screen.getWindow().getSize().x/2.f - 125.f, 50.f));
	board = new Game_Board(sf::Vector2f(100.f, 50.f));
	board2 = new Game_Board(sf::Vector2f(100.f, 50.f));


	Ship_Display* ship1 = new Ship_Display(sf::Vector2f(800.f, 200.f));
	ship1->set_rectangle_size(sf::Vector2f(100.f, 50.f));
	ship1->set_Texture("Res/Ship_Picture.jpg");
	//ship1->flip_orien();


	while (!m_screen.isClosed())
	{
		std::vector<Object *> Objects_to_render;
		sf::Vector2i click;
		switch (m_game_state)
		{
		case MENU:
			Objects_to_render.push_back(menu);
			menu->switchStates((menu->getClickedItem(m_screen)), *this);
			break;
		case BATTLE:
			click = (*board).getClickedTile(m_screen);
			if (m_player)
			{
				battle_loop(click.x, click.y);
				if (isWon())
				{
					board->switchStates(1, *this);
				}
				Objects_to_render.push_back(board);
				(*board).colorTile(click);
			}
			else
			{
				battle_loop(click.x, click.y);
				if (isWon())
				{
					board->switchStates(1, *this);
				}
				Objects_to_render.push_back(board2);
				(*board2).colorTile(click);
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
			}
			else
			{
				return;
			}
		}
		else
			if (board2->check_Tile(x - 1, y - 1) == board2->boat || board2->check_Tile(x - 1, y - 1) == board2->empty)
			{
				board2->update_Board(pair<int, int>(x - 1, y - 1));
				m_player = true;
			}
			else
			{
				return;
			}
	}
}

