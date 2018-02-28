#pragma once
#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED
#include<utility>
#include"Board.h"
using std::pair;


//do all the player shooting and do the context switching between players
class AI
{
public:
	enum state {no_Hit = 0, one_Hit, two_Hit, three_Hit, done};
private:
	pair<int, int> _hit;  //maybe make a bool to trigger to try a smart shot
	int _num_Hits;
public:
	AI();

	void made_Hit(pair<int,int> location);

	//**********************Functions that Control AI Shooting **************************************************

	//checks to ensure that a shot is not repeated
	bool valid_Shot(int row, int col, Game_Board & board);

	//finds the coordinate for the next shot to be made randomly
	void make_Shot(Game_Board & board);

	// If a ship has been hit pick the next shots intelligently
	void smart_Shot(Game_Board & board);

	/*
	void state_One_Hit();
	void state_2nd_Hit_Forward();
	void state_2nd_Hit_Reverse();
	bool check_Destroyed();
	*/
};
#endif // !AI_H_INCLUDED

