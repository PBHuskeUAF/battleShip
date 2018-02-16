#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Screen
{
	const int WIDTH = 1000, HEIGHT = 600;
public:
	Screen(); //Sets up Screen
	void render();
	void handleEvents();
	bool isClosed() { return m_isClosed; }
	void close();

	sf::Vector2i& get_mouse_position() { return m_mouse_position; }
	bool is_mouse_pressed() { return m_mouse_is_pressed; }
	
private:
	bool m_isClosed;
	sf::RenderWindow m_window;
	//sf::Texture m_temp_board_texture;
	//sf::RectangleShape m_temp_rect_shape;

	//mouse stuff
	sf::Vector2i m_mouse_position;
	bool m_mouse_is_pressed;

	//keyboard stuff

};

class Section
{
public:
	Section(sf::Vector2f & m_pos); //Takes window to draw to
	virtual void render(sf::RenderWindow& window) = 0;
protected:
	sf::Vector2f m_pos; //position of section on board
};


class Board: public Section
{
public:
	Board( sf::Vector2f m_pos);
	void render(sf::RenderWindow& window);
private:
	sf::Texture m_temp_board_texture;
	sf::RectangleShape m_temp_rect_shape;
};


#endif
