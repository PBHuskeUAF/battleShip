#include "Screen.h"
#include <iostream>
#include "Ship.h"

Screen::Screen()
{
	m_window.create(sf::VideoMode(WIDTH, HEIGHT), "My window", sf::Style::Close);


	//if (!m_temp_board_texture.loadFromFile("Tile_Ocean.jpg"))
	//{
	//	std::cout << "File not found" << std::endl;
	//	m_temp_rect_shape.setFillColor(sf::Color::Blue);

	//}
	//else
	//	std::cout << "file found" << std::endl;

	m_isClosed = false;
	//m_temp_rect_shape.setSize(sf::Vector2f(50.f, 50.f));
	//m_temp_rect_shape.setFillColor(sf::Color::Red);
	//m_temp_rect_shape.setTexture(&m_temp_board_texture);

	m_mouse_is_pressed = false;
	m_mouse_position = sf::Vector2i(0, 0);
}

sf::Vector2i & Screen::getPosition()
{
	return m_window.getPosition();
}

void Screen::render()
{

	Board board(sf::Vector2f(100., 50.));
	board.render(m_window);
	board.getClickedTile(*this);

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
		//std::cout << "File not found" << std::endl;
		m_temp_rect_shape.setFillColor(sf::Color::Blue);

	}
	else
		//std::cout << "file found" << std::endl;

	if (!m_font.loadFromFile("AdobeArabic-Bold.otf"))
	{
		//std::cout << "font not found" << std::endl;
	}
	else
	{
		//std::cout << "font found" << std::endl;
	}


	m_temp_rect_shape.setSize(sf::Vector2f(50.f, 50.f));
	//m_temp_rect_shape.setFillColor(sf::Color::Red);
	m_temp_rect_shape.setTexture(&m_temp_board_texture);
}

void Board::getClickedTile(Screen & screen)
{
	if (screen.is_mouse_pressed())
	{
		//std::cout << m_pos.x << " " << m_pos.y << std::endl;
		//std::cout << screen.get_mouse_position().x << " " << screen.get_mouse_position().y << std::endl;



		float xpos = screen.get_mouse_position().x - screen.getPosition().x - m_pos.x - 6.8; //Don't ask me why these extra numbers are nessessary,
		float ypos = screen.get_mouse_position().y - screen.getPosition().y - m_pos.y - 30; //I have no idea.
		xpos /= m_temp_rect_shape.getSize().x;
		ypos /= m_temp_rect_shape.getSize().y;

		xpos = std::floor(xpos)+1;
		ypos = std::floor(ypos)+1;
		std::cout << xpos << " " << ypos << std::endl;
	}
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
				m_temp_rect_shape.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*(i-1) + m_pos.x),
					(float)(m_temp_rect_shape.getSize().y*(j-1)) + m_pos.y));
				window.draw(m_temp_rect_shape);
			}

		}
	}
	ship1.render(window,m_pos);
	ship2.render(window, m_pos);
	ship3.render(window, m_pos);

}