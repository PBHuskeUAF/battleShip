#ifndef GAME_H
#define GAME_H

class Screen;

#include "Screen.h"

class Game
{
private:
	Game();
	void main_loop();
	void battle_loop();
public:
	enum State { MENU, BATTLE, OPTIONS, EXIT };
	static void start();
	void change_state(Game::State state);
private:
	int m_player;
	Screen m_screen;
	State m_game_state;
};
#endif