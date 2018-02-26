#include "AI.h"


AI::AI()
{

}

//********************************Functions Involved with AI and Shooting

//checks to make sure the generated shot is not a repetition of old shots
bool AI::valid_Shot(pair<int, int> coord, Game_Board & board)
{

	Game_Board::tile_Type tile = board.check_Tile(coord.first, coord.second);
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
		if (valid_Shot(attempt, board))
		{
			board.update_Board(coord);
			coord = attempt;
			break;
		}
	}
}

void AI::smart_Shot(Game_Board & board)
{

}
