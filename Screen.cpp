#include <iostream>
#include "Headers/Game_Header_List.h"


Screen::Screen()
{
	m_window.create(sf::VideoMode(WIDTH, HEIGHT), "My window", sf::Style::Close);
	m_mouse_is_pressed = false;
	m_mouse_position = sf::Vector2i(0, 0);
	for (int i = 0;i < 150; i++)
	{
		m_key_pressed[i] = false;
	}
}

sf::Vector2i & Screen::getPosition()
{
	return m_window.getPosition();
}

void Screen::render(std::vector<Object *> Objects_to_render)
{
	m_window.clear();
	for (auto i : Objects_to_render)
	{
		i->render(*this);
	}


	//(*m_board).render(*this);
	//(*m_board).colorTile((*m_board).getClickedTile(*this));

	m_window.display();
}

void Screen::handleEvents()
{
	sf::Event event;

	for (int i = 0; i < 150;i++)
	{
		m_key_click[i] = false;
	}

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			m_key_pressed[event.key.code] = true;
			//std::cout << "pressed" << std::endl;
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			m_key_click[event.key.code] = m_key_pressed[event.key.code];
			m_key_pressed[event.key.code] = false;
			//std::cout << "unpressed" << std::endl;
		}
	}

	m_mouse_button_clicked = (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) && m_mouse_is_pressed;
	m_mouse_is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	m_mouse_position = sf::Mouse::getPosition();

	for (int i = 0;i < 150;i++)
	{
		if (m_key_pressed[i])
			std::cout << i << "Pressed" << std::endl;
	}

	//std::cout << m_mouse_is_pressed << std::endl;
}

void Screen::close()
{
	//set isClosed to true
	m_isClosed = true;
}

bool Screen::isKeyPressed(sf::Keyboard::Key key)
{
	return m_key_pressed[key];
}

bool Screen::isKeyClicked(sf::Keyboard::Key key)
{
	return m_key_click[key];
}
