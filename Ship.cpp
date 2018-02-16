#include "Ship.h"

GenericTestShip::GenericTestShip()
{
	int m_size = 3;
	m_Position.resize(2);
	m_Position.at(0) = 0;
	m_Position.at(1) = 0;
	m_dir = HORIZ;
	m_shape.setSize(sf::Vector2f(150.f, 50.f));
	m_shape.setPosition(sf::Vector2f(0.f, 0.f));
	m_shape.setFillColor(sf::Color::Red);
}

GenericTestShip::GenericTestShip(int size, DIRECTION dir, std::vector<float>& position)
{
	m_size = size;
	m_dir = dir;
	m_Position = position;

	if(m_dir == HORIZ)
		m_shape.setSize(sf::Vector2f((float)50.f*m_size, (float)50.f));
	else
		m_shape.setSize(sf::Vector2f((float)50.f, (float)m_size*50.f));

	m_shape.setPosition(sf::Vector2f(50.*m_Position.at(1), 50.*m_Position.at(0)));
	m_shape.setFillColor(sf::Color::Red);

}

void GenericTestShip::render( sf::RenderWindow& window)
{
	window.draw(m_shape);
}