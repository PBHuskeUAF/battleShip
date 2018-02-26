#pragma once
#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED 
#include "Level.h"
class AI
{

public:
	AI();
	//**********************Functions that Control AI Shooting **************************************************

	//checks to ensure that a shot is not repeated
	bool valid_Shot(pair<int, int> coord, Game_Board & board);

	//finds the coordinate for the next shot to be made randomly
	void make_Shot(Game_Board & board);

	// If a ship has been hit pick the next shots intelligently
	void smart_Shot(Game_Board & board);

};
#endif // !AI_H_INCLUDED

