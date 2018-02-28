#ifndef GAME_H
#define GAME_H

class Screen;

#include "Screen.h"

class Game
{
private:
	Game();
	void main_loop();
	void battle_loop(int x, int y);
public:
	enum State { MENU, BATTLE, OPTIONS, EXIT };
	static void start();
	void change_state(Game::State state);
	bool isWon();
private:
	bool m_player;
	Screen m_screen;
	State m_game_state;
	bool setUp;
	Game_Board* board;
	Game_Board* board2;
	bool just_entered;
};
#endif