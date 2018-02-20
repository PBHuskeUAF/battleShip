#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Screen.h"
#include "Ship.h"
#include "Board.h"

const int WIDTH = 1200;
const int HEIGHT = 600;

void poll_keyBoard()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		std::cout << "Left Key Pressed" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		std::cout << "Right Key Pressed" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		std::cout << "UP Key Pressed" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		std::cout << "Down Key Pressed" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		std::cout << "Escape Key Pressed" << std::endl;
}

int main()
{
	Screen screen;
	while (!screen.isClosed())
	{
		screen.handleEvents();
		screen.render();
	}



	return 0;
}