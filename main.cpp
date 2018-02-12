#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window",sf::Style::Close);
	sf::Texture texture;
	if (!texture.loadFromFile("Tile_Ocean.jpg"))
		std::cout << "File not found" << std::endl;
	else
		std::cout << "file found" << std::endl;
		
	sf::Sprite sprite;
	float scale = .05;
	sprite.setScale(sf::Vector2f(scale,scale));
	sprite.setTexture(texture);
	sf::CircleShape circ(50);


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		for (int i = 0;i < 10;i++)
		{
			for (int j = 0;j < 10;j++)
			{
				sprite.setPosition(sf::Vector2f((float)((70)*i), (float)(70*j) ));
				window.draw(sprite);

			}
		}
		//window.draw(sprite);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}

	return 0;
}