#include "Screen.h"
#include <iostream>
#include "Ship.h"


Game_Level game;

Screen::Screen()
{
	m_window.create(sf::VideoMode(WIDTH, HEIGHT), "My window", sf::Style::Close);


	m_mouse_is_pressed = false;
	m_mouse_position = sf::Vector2i(0, 0);

	m_board = new Board(sf::Vector2f(100.f, 50.f));

}

sf::Vector2i & Screen::getPosition()
{
	return m_window.getPosition();
}

void Screen::render()
{
	(*m_board).render(m_window);
	(*m_board).colorTile((*m_board).getClickedTile(*this));

	m_window.display();
}

void Screen::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			close();
	}

	m_mouse_is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	m_mouse_position = sf::Mouse::getPosition();
	//std::cout << m_mouse_is_pressed << std::endl;
}

void Screen::close()
{
	//what do I do here?

	//set isClosed to true
	m_isClosed = true;
}

//////////////////////////////////////////////////////////////////////
//         Section                                                  //
//////////////////////////////////////////////////////////////////////
Section::Section(sf::Vector2f & pos)
{
	m_pos = pos;
}


//////////////////////////////////////////////////////////////////////
//			Board Class                                             //
//////////////////////////////////////////////////////////////////////

Board::Board(sf::Vector2f m_pos) :Section(m_pos)
{

	if (!m_temp_board_texture.loadFromFile("Tile_Ocean.jpg"))
	{
		std::cout << "File not found" << std::endl;
		m_temp_rect_shape.setFillColor(sf::Color::Blue);

	}
	else
		std::cout << "file found" << std::endl;

	if (!m_font.loadFromFile("AdobeArabic-Bold.otf"))
	{
		std::cout << "font not found" << std::endl;
	}
	else
	{
		std::cout << "font found" << std::endl;
	}


	for (int i = 0;i < 100;i++)
	{
		m_is_hit[i] = false;
	}

	m_temp_rect_shape.setSize(sf::Vector2f(50.f, 50.f));
	//m_temp_rect_shape.setFillColor(sf::Color::Red);
	m_temp_rect_shape.setTexture(&m_temp_board_texture);
}

sf::Vector2i& Board::getClickedTile(Screen & screen)
{
	if (screen.is_mouse_pressed())
	{
		float xpos = screen.get_mouse_position().x - screen.getPosition().x - m_pos.x - 6.8; //Don't ask me why these extra numbers are nessessary,
		float ypos = screen.get_mouse_position().y - screen.getPosition().y - m_pos.y - 30; //I have no idea.
		xpos /= m_temp_rect_shape.getSize().x;
		ypos /= m_temp_rect_shape.getSize().y;

		xpos = std::floor(xpos)+1;
		ypos = std::floor(ypos)+1;
		return sf::Vector2i(xpos, ypos);
	}
	return sf::Vector2i(-1, -1);
}

void Board::render(sf::RenderWindow& window)
{
	sf::Text text;
	text.setFont(m_font);

	window.clear(sf::Color::Black);
	GenericTestShip ship1(3, GenericTestShip::HORIZ, std::vector<float>{1.f, 0.f});
	GenericTestShip ship2(5, GenericTestShip::VERT, std::vector<float>{5.f, 5.f});
	GenericTestShip ship3(3, GenericTestShip::HORIZ, std::vector<float>{9.f, 0.f});


	for (int i = 0;i <= 10;i++)
	{
		for (int j = 0;j <= 10;j++)
		{
			if ((j == 0) && (i!= 0))
			{
				text.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i-1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j-1)) + m_pos.y));
				text.setString(std::to_string(i));
				window.draw(text);
			}
			else if ((j != 0) && (i == 0))
			{
				text.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i-1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j-1)) + m_pos.y));
				text.setString((char)(j - 1 + 'a'));
				window.draw(text);
			}
			else if ((j == 0) && (i == 0))
			{
				continue;
			}
			else
			{


				if (m_is_hit[10 * (i - 1) + (j - 1)])
				{
					m_temp_rect_shape.setFillColor(sf::Color::Green);
				}
				if(game.getBoard()[10*(i-1) + (j-1)] == 1)
				{
					m_temp_rect_shape.setFillColor(sf::Color::Red);
				}

				m_temp_rect_shape.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i-1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j-1)) + m_pos.y));
				window.draw(m_temp_rect_shape);
			}
			m_temp_rect_shape.setFillColor(sf::Color::White);

		}
	}
	//ship1.render(window,m_pos);
	//ship2.render(window, m_pos);
	//ship3.render(window, m_pos);

}

void Board::colorTile(sf::Vector2i & hit)
{
	if ((hit.x <= 0) || (hit.y <= 0)||hit.x > 10 || hit.y > 10)
	{
		return;
	}
	else
	{
		m_is_hit[10 * (hit.x - 1) + (hit.y - 1)] = true;
	}
}