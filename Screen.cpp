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

void Screen::render()
{

	Board board(sf::Vector2f(50., 0.));
	board.render(m_window);

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

	m_temp_rect_shape.setSize(sf::Vector2f(50.f, 50.f));
	//m_temp_rect_shape.setFillColor(sf::Color::Red);
	m_temp_rect_shape.setTexture(&m_temp_board_texture);
}

void Board::render(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	GenericTestShip ship1(3, GenericTestShip::HORIZ, std::vector<float>{1.f, 0.f});
	GenericTestShip ship2(5, GenericTestShip::VERT, std::vector<float>{5.f, 5.f});
	GenericTestShip ship3(3, GenericTestShip::HORIZ, std::vector<float>{9.f, 0.f});

	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			m_temp_rect_shape.setPosition(sf::Vector2f((float)(m_temp_rect_shape.getSize().x*i + m_pos.x),
				(float)(m_temp_rect_shape.getSize().y*j) + m_pos.y));
			window.draw(m_temp_rect_shape);

		}
	}
	ship1.render(window,m_pos);
	ship2.render(window, m_pos);
	ship3.render(window, m_pos);

}