#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Screen.h"


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

void poll_mouse()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		std::cout << "left mouse button pressed" << std::endl;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		std::cout << "right mouse button pressed" << std::endl;
}



int main()
{
	
	// create the window
	//sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window",sf::Style::Close);
	//sf::Texture texture;
	//if (!texture.loadFromFile("Tile_Ocean.jpg"))
	//	std::cout << "File not found" << std::endl;
	//else
	//	std::cout << "file found" << std::endl;
		
	//sf::Sprite sprite;
	//float rect_size = 50.f;
	//sf::RectangleShape rect(sf::Vector2f(rect_size, rect_size));
	//float scale = .05;
	//sprite.setScale(sf::Vector2f(scale,scale));
	//sprite.setTexture(texture);
	//rect.setTexture(&texture);
	//sf::CircleShape circ(50);


	// run the program as long as the window is open
	//while (window.isOpen())
	//{
		// check all the window's events that were triggered since the last iteration of the loop
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
			// "close requested" event: we close the window
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}


	//	poll_mouse();
	//	poll_keyBoard();

		// clear the window with black color
	//	window.clear(sf::Color::Black);

	//	for (int i = 0;i < 10;i++)
	//	{
	//		for (int j = 0;j < 10;j++)
	//		{
	//			rect.setPosition(sf::Vector2f((float)(rect_size*i), (float)(rect_size*j) ));
	//			window.draw(rect);

	//		}
	//	}
		//window.draw(sprite);

		// draw everything here...
		// window.draw(...);

		// end the current frame
	//	window.display();
	//}

	Screen screen;
	while (!screen.isClosed())
	{
		screen.handleEvents();
		screen.render();
	}



	return 0;
}