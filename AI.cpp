#include "AI.h"

AI::AI()
{
	_hit = std::pair<int,int>(0, 0);
	_num_Hits = 0;
	//state = no_Hit;
}

void AI::made_Hit(pair<int, int> location)
{
	_hit = location;
	_num_Hits++;
}
//********************************Functions Involved with AI and Shooting

//checks to make sure the generated shot is not a repetition of old shots
bool AI::valid_Shot(int row, int col, Game_Board & board)
{
	Game_Board::tile_Type tile = board.check_Tile(row, col);
    if (tile == Game_Board::miss || tile == Game_Board::hit) // already used this square before
		return false;
	else
		return true; // empty spot nothing is there
}

//Generates random shot, checks if it is a repeat shot, if not updates the board to reflect new shot.
void AI::make_Shot(Game_Board & board)
{
	pair<int, int> coord;
	while (1)
	{
		pair<int, int> attempt = board.gen_Random();
		if (valid_Shot(attempt.first, attempt.second, board))
		{
			if (board.check_Tile(attempt.first, attempt.second) == Game_Board::boat)
				made_Hit(coord);//update this later to help with finding the endgame
			board.update_Board(coord);
			coord = attempt;
			break;
		}
	}
}

void AI::smart_Shot(Game_Board & board)
{
	int row = _hit.first;
	int col = _hit.second;
	/*
     //pick a random cardinal direction to try for 2nd hit
	pair<int, int> rand = board.gen_Random();
	int corner = rand.first % 4;
	if (_num_Hits == 0) //make it some type of loop so that if a shot is not valid it will not try it either
	{
		switch (corner)//cycle through these until one works
		{
		case 1: //fire to right
			col++;
			if (valid_Shot(row, col, board)
			{

			}
			break;
		case 2:  //fire above
			row--;
			if (valid_Shot(row, col, board)
			{

			}
			break;
		case 3:   //fire to left
			col--;
			if (valid_Shot(row, col, board)
			{

			}
			break;
		case 4:   //fire below
			row++;
			if (valid_Shot(row, col, board)
			{

			}
			
		}

	}
	*/
}
