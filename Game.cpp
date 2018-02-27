#include "Headers/Game_Header_List.h"
#include <iostream>

Game::Game()
{
	m_game_state = MENU;
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

void Game::main_loop()
{
	Menu* menu = new Menu(sf::Vector2f(m_screen.getWindow().getSize().x/2.f - 125.f, 50.f));
	Game_Board* board = new Game_Board(sf::Vector2f(100.f, 50.f));
	while (!m_screen.isClosed())
	{
		std::vector<Object *> Objects_to_render;

		switch (m_game_state)
		{
		case MENU:
			Objects_to_render.push_back(menu);
			menu->switchStates((menu->getClickedItem(m_screen)), *this);
			//update logic
			//draw menu
			break;
		case BATTLE:
			Objects_to_render.push_back(board);
			(*board).colorTile((*board).getClickedTile(m_screen));
			//update logic
			//draw board
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

