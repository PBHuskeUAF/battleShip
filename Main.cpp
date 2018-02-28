

//for testing functionality of the Battleship Game 
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//#include "Game_Header_List.h"
//#include"Ship.h"
//#include"Board.h"
#include "Level.h"
//#include <SFML/Graphics.hpp>

#include<iostream>
using std::cout;

//using namespace sf;


TEST_CASE("Make Board set and read tiles") {

	Game_Board* test = new Game_Board(100);
	int sum = 0;
	int sum2 = 0;
	test->set_Tile(3, Game_Board::boat);

	test->set_Tile(4, Game_Board::boat);

	for (int j = 0; j < 10; j++)
	{

		if (test->check_Tile(0, j) == Game_Board::boat)
		{
			cout << " X ";
			sum++;
		}
		else if (test->check_Tile(0, j) == Game_Board::empty)
		{
			cout << " E ";
		}

	}
	REQUIRE(sum2 == 2);

	test->set_Tile(33, Game_Board::boat);

	test->set_Tile(34, Game_Board::boat);
	
	for (int j = 0; j < 10; j++)
	{

		if (test->check_Tile(3, j) == Game_Board::boat)
		{
			cout << " X ";
			sum2++;
		}
		else if (test->check_Tile(3, j) == Game_Board::empty)
		{
			cout << " E ";
		}

	}
	REQUIRE(sum2 == 2);
	
}



TEST_CASE("Make Ships and verify properties") {


	Game_Board * test = new Game_Board(100);

	Ship::ship_Type c = Ship::carrier;
	Ship *Sh = new Ship(c, test);
	Ship t;

	REQUIRE(t.get_Size() == 5);
	REQUIRE(t.get_Orientation() == Ship::vertical);
	REQUIRE(t.get_Life() == 5);
	pair<int, int> origin = pair<int, int>(0, 0);
	REQUIRE(t.get_Location() == origin);
}


TEST_CASE("Fleet Generation") {

	int ship_Counter = 0;

	Game_Board * test = new Game_Board(100);
	vector < Ship > _fleet;
	vector<int> number_of_ship_by_Types = { 1, 2, 3, 4, 5 }; // the number of each ships carrier, battleship, cruiser, sub, destroyer
	for (int i = 0; i < number_of_ship_by_Types.size(); i++)//for every class of ship
	{
		for (int j = 0; j < number_of_ship_by_Types[i]; j++)//for the number of ships in each class
		{
			Ship S = Ship(static_cast<Ship::ship_Type>(i), test) ;
			_fleet.push_back(S);//generate the ships and put them into a vector


			pair<int, int> coord = _fleet[ship_Counter].get_Location();
			int row = coord.first;
			int col = coord.second;
			int size = _fleet[j].get_Size();
			Ship::ship_Dir orien = _fleet[j].get_Orientation();
			++ship_Counter;
		}

	}
	int _s = _fleet.size();
	int last = _s - 1;
	cout << "\n\n" << _s << " \n\n";
	

	for (int i = 0; i < _s; i++)
	{
		pair<int, int> temp = _fleet[i].get_Location();
		cout << _fleet[i].get_Size() << " " << _fleet[i].get_Orientation() << " " << temp.first<< " " << temp.second;

			cout << "\n\n";

	}
	REQUIRE(_fleet[0].get_Size() == 5);
	REQUIRE(_fleet[1].get_Size() == 4);
	REQUIRE(_fleet[last].get_Size() == 2);
	cout << "done with Ships /n";
}


TEST_CASE("Ship Overlap") {


	vector<int> imagine = { 51,61,71 };

	Game_Level one;
	one.update_Board(imagine);
	auto y = one._battle_Board;
	cout << "\n This is testing the Game level update test \n\n";
	for (int i = 0; i < 10; i++)
	{
		Game_Board::tile_Type temp = y->check_Tile(i, 1);
		if (temp == Game_Board::boat)
			cout << " x ";
		else
			cout << " 0 ";
	}
	cout << "\n";

	Game_Board* test = new Game_Board(100);

	Ship::ship_Type c = Ship::carrier;
	int sum = 0;
	Ship t = Ship(c, test);
	test->set_Tile(43, Game_Board::boat);
	test->set_Tile(53, Game_Board::boat);
	test->set_Tile(63, Game_Board::boat);

	REQUIRE(t.in_Bounds(11,5) == false);
	REQUIRE(t.in_Bounds(4, 12) == false);
	REQUIRE(t.in_Bounds(10, 10) == false);
	REQUIRE(t.in_Bounds(1, 1) == true);
	cout << " In bounds tested";

	t.set_Location( pair<int, int>(3,9));
	t.set_Orientation( Ship::horizontal);

	REQUIRE(t.ship_Overlap(4, 3, test) == true);
	REQUIRE(t.ship_Overlap(4, 4, test) == false);
}

TEST_CASE("Game_level Object") {

	Game_Level one;
	one.generate_Ships();
	int sum = 0;
	Game_Board * test = one._battle_Board;//error here
	for (int i = 0; i < 10; i++)
	{
		cout << std::endl;
		for (int j = 0; j < 10; j++)
		{
			
			if (test->check_Tile(i, j) == Game_Board::boat)
			{
				cout << " X ";
				sum++;
			}
			else if(test->check_Tile(i, j) == Game_Board::empty)
			{
				cout << " E ";
			}
			
		}

	}

	cout << "THis is the end of the Game_Level Tests";
	REQUIRE(sum == 44);
}

TEST_CASE("Test AI") {

}
	
	/*
	const float FPS = 30.0f; //The desired FPS. (The number of updates each second).
	bool redraw = true;      //Do I redraw everything on the screen?

	RenderWindow window(VideoMode(300, 300, 32), "Hello");
	window.setFramerateLimit(FPS);
	Clock clock;
	CircleShape circle(10.0f);
	circle.setOrigin(10.0f, 10.0f);
	circle.setPosition(0, 150.0f);

	Event ev;
	while (window.isOpen())
	{
		//Wait until 1/60th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / FPS)
		{
			redraw = true; //We're ready to redraw everything
			circle.move(1.0f, 0);
			clock.restart();
		}

		//Handle input
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed) window.close();
		}

		//Draw stuff if ready
		if (redraw)
		{
			redraw = false;
			window.clear(Color(0, 0, 0));
			window.draw(circle);
			window.display();
		}
	}
	/*
	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Hello SFML", sf::Style::Default);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(200, 200);
	text.setString("Hello SFML");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(text);
		window.display();
	}
	*/
	//return 0;
//}