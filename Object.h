#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Screen;

class Object
{
public:
	Object(sf::Vector2f & m_pos); //Takes window to draw to
	virtual void render(Screen & screen) = 0;
protected:
	sf::Vector2f m_pos; //position of section on board
};