// Ship.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include<utility>
#include <random> 
#include <functional>
#include<vector>
using std::pair;
using std::cout;
using std::endl;
const int WIDTH = 800;
const int HEIGHT = 600;

pair <int, int> gen_random()
{
	pair<int, int> coordinates;

	std::random_device rd;
	std::uniform_int_distribution<int> distribution(0, 9);
	std::mt19937 engine(rd()); // Mersenne twister MT19937 
	auto generator = std::bind(distribution, engine);
	int random = generator();  // Generate a uniform integral variate between 0 and 99.

	  
	int row = distribution(engine); // generate random coordinates
	int col = distribution(engine);
	coordinates.first = row;
	coordinates.second = col;
	return coordinates;
}


bool valid_Shot(pair<int, int> coord, int * board)
{
	int index = coord.first * 10 + coord.second;
	if (board[index]) // something is already there
		return false;
	else
		return true; // empty spot nothing is there
}

pair<int, int>  Shoot()
{
	pair<int, int> coord;
	while (1)
	{
		pair<int, int> attempt = gen_random();
		if (valid_Shot(attempt))
		{
			coord = attempt;
		break;
		}
	}
	//Need to implement that hash table shifting to closest valid move.
	return coord;
}

bool in_Bounds(int row, int col)
{
	if (row <10 && row > -1 && col <10 && col > -1)
		return true;
	else
		return false;
}

pair<char, char> another_Hit(int row, int col)
{
	

}



pair<int, int> Ship_hit(pair<int, int> coord)
{
	int row = coord.first;
	int col = coord.second;
	//Create some sort of structure to convey a vertical or horizontal orientation and start and stop of the hit sequence
	//make this process its own function
	//The next hit will take in this info and then decide on the next shot based on that

	//Find out number of hits chained
	if (in_Bounds(row + 1, col))//check right
	{
		another_Hit(row + 1, col);
	}
	else if (in_Bounds(row, col - 1)) //up
	{
		another_Hit(row, col-1);
	}
	else if (in_Bounds(row-1, col)) //left
	{
		another_Hit(row - 1, col);
	}
	else if (in_Bounds(row, col + 1)) //down
	{
		another_Hit(row, col+1);
	}

	//if no chain
	//launch at one of the four coordinate left

	//if chain >=2 continue in best direction
	pair<int, int> next_Coord;

	return next_Coord;
}

int main()
{
	
    return 0;
}

/*  

tests to confirm randomness


std::vector<int> primes;
int arr[100];
for (int i = 0; i < 99; i++)
{
pair<int, int> a = Shoot();
//cout << a.first << "     " << a.second << "\n";
primes.push_back(a.first);
primes.push_back(a.second);
}
int x = 0;
for (int i = 0; i < 99; i++)
{
arr[i] = 0;
}
for (int i = 0; i < primes.size(); i++)
{
arr[primes[i]]+=1;
}

for (int i = 0; i < 99; i++)
{
cout<<arr[i]<<endl;
}
*/