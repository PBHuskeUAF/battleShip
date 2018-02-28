#include "Level.h"
#include <memory>
#include<vector>
using std::vector;

Game_Level::Game_Level(): _Number_of_Tiles(100), _battle_Board(Game_Board(_Number_of_Tiles)){}


//Call Ships to be generated
void Game_Level::generate_Ships()
{
	vector < std::unique_ptr<Ship> > fleet;
	vector<int> number_of_ship_by_Types = { 1, 2, 3, 3, 4, 5 }; // the number of each ships carrier, battleship, cruiser, sub, destroyer
	for (int i = 0; i < number_of_ship_by_Types.size(); i++)//for every class of ship
	{
		for (int j = 0; j < number_of_ship_by_Types[i]; j++)//for the number of ships in each class
		{

			fleet.push_back(std::make_unique<Ship>((Ship::ship_Type) i, _battle_Board));//generate the ships and put them into a vector
			pair<int, int> coord = fleet[j]->get_Location();
			int row = coord.first;
			int col = coord.second;
			int size = fleet[j]->get_Size();
			Ship::ship_Dir orien = fleet[j]->get_Orientation();

			_battle_Board->ship_to_Board(row, col, orien, size);//update the board so that the next ship won't overlap previous ships
		}

	}

}
