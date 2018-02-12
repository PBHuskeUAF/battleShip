#pragma once
#include<utility>
using std::pair;
class Player //abstract class?
{
private:
	pair<int, int> coordinates;
	bool confirm;// ??? may not be necessary

public:
	pair<int, int> computer_Decision();
};
