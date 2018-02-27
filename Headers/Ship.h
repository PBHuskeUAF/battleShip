#ifndef  SHIP_H_INCLUDED
#define SHIP_H_INCLUDED


#include<vector>
#include<utility>
using std::pair;
using std::vector;


class Game_Board;

//creates ships and holds their values
class Ship
{
public:

static enum ship_Type { carrier = 0, battleship, cruiser, submarine, destroyer };
enum ship_Dir {horizontal = 0, vertical };
private:
	//type of ship
	ship_Type _type;
	//size
	int _size;
	//position row column for one end of the ship
	pair<int, int> _location;
	//life or hits
	int _life;
	//orientation  1 = vertical 0 = horizontal
	ship_Dir _orientation;

public:
	//constructors
	Ship();
	Ship(ship_Type type, Game_Board & board);

	// **********************************member functions******************************************************

	//bool is_Destroyed();
	//bool is_Hit(int r, int col);

	ship_Dir get_Orientation();
	void set_Orientation(ship_Dir orient);

	pair<int, int> get_Location();
	void set_Location(pair<int,int> location);

	int get_Size();
	void set_Size( int size);

	int get_Life();
	void set_Life( int life);

	//*****************************Functions that Determine Ship Placement********************************

	//generate a random orientation for a ship
	Ship::ship_Dir gen_Orientation(Game_Board & board);
	//checks to see if ship is in bounds
	bool in_Bounds(int row, int col);

	//checks to see if the tentative ship location will cause it to overlap a previous ship
	bool ship_Overlap(int row, int col, Game_Board & board);

	//returns the location of the ship after calling valid location functions
	pair <int, int> place_Ship(Game_Board & board);	
};

class Ship_Display: public Object
{
public:
	Ship_Display(sf::Vector2f pos): Object(pos){}
	void render();
private:

};

#endif
