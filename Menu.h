#pragma once
#include "Object.h"

class Screen;
class Game;

class Menu : public Object
{
public:
	Menu(sf::Vector2f m_pos);
	int getClickedItem(Screen & screen);
	void render(Screen & screen);
	void switchStates(int state, Game& game);
private:
	sf::Font m_font;
	sf::RectangleShape m_border;
};
