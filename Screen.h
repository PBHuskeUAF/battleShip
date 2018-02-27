#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Object.h"

class Game_Board;
class Ship;
class Game;
class Object;

class Screen
{
	const int WIDTH = 1000, HEIGHT = 600;
public:
	Screen(); //Sets up Screen
	sf::Vector2i & getPosition();
	void render(std::vector<Object *> Objects_to_render);
	void handleEvents();
	void close();

	bool isClosed() { return m_isClosed; }
	bool is_mouse_pressed() { return m_mouse_is_pressed; }

	sf::Vector2i& get_mouse_position() { return m_mouse_position; }
	sf::RenderWindow & getWindow() { return m_window; }
private:
	bool m_isClosed;
	sf::RenderWindow m_window;
	//mouse stuff
	sf::Vector2i m_mouse_position;
	bool m_mouse_is_pressed;
	//keyboard stuff
	bool m_key_pressed[150];
};
#endif
