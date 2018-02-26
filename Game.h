#ifndef GAME_H
#define GAME_H

class Screen;

#include "Screen.h"

class Game
{
private:
	Game();
public:
	enum State { MENU, BATTLE, OPTIONS, EXIT };
	static void start();
	void change_state(Game::State state);
private:
	void main_loop();
	Screen m_screen;
	State m_game_state;
};
#endif