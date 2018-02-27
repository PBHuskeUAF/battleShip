#include "Game_Header_List.h"
#include <iostream>

Menu::Menu(sf::Vector2f m_pos) : Object(m_pos)
{
	if (!m_font.loadFromFile("Res/AdobeArabic-Bold.otf"))
	{
		std::cout << "font not found" << std::endl;
	}
	else
	{
		std::cout << "font found" << std::endl;
	}
	m_border.setSize(sf::Vector2f(200.f, 500.f));
	m_border.setFillColor(sf::Color::Blue);
	m_border.setPosition(m_pos);
}

int Menu::getClickedItem(Screen & screen)
{
	float xpos = screen.get_mouse_position().x - screen.getPosition().x - m_pos.x - 6.8; //Don't ask me why these extra numbers are nessessary,
	float ypos = screen.get_mouse_position().y - screen.getPosition().y - m_pos.y - 30; //I have no idea.

	if (!screen.is_mouse_pressed())
	{
		return 0;
	}


	if (xpos < 50.f || xpos > 150.f)
		return 0;
	if (ypos > (70.f - 20.f) && ypos < (70.f + 20.f))
		return 1;
	if (ypos >(170.f - 20.f) && ypos < (170.f + 20.f))
		return 2;
	if (ypos >(270.f - 20.f) && ypos < (270.f + 20.f))
		return 3;

	return 0;
}

void Menu::render(Screen & screen)
{
	screen.getWindow().draw(m_border);
	sf::Text text;
	text.setFont(m_font);
	text.setPosition(sf::Vector2f(m_pos.x + 50.f, m_pos.y + 50.f));
	text.setString("Play Game");
	screen.getWindow().draw(text);
	text.setPosition(sf::Vector2f(m_pos.x + 50.f, m_pos.y + 150.f));
	text.setString("Options");
	screen.getWindow().draw(text);
	text.setPosition(sf::Vector2f(m_pos.x + 50.f, m_pos.y + 250.f));
	text.setString("Quit");
	screen.getWindow().draw(text);
}

void Menu::switchStates(int state, Game& game)
{
	if (state == 1)
	{
		game.change_state(Game::BATTLE);
		std::cout << "State Changed" << std::endl;
	}
	else if (state == 2)
	{
		//game.change_state(Game::OPTIONS);
	}
	else if (state == 3)
	{
		game.change_state(Game::EXIT);
	}
}