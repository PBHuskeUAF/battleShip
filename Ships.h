#pragma once

#include <SFML\Graphics.hpp>
#include<vector>


class GenericTestShip
{
public:
	enum DIRECTION{ VERT, HORIZ };
	GenericTestShip();
private:
	std::vector<int> m_Position;
	DIRECTION m_dir;
	int size;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
};
