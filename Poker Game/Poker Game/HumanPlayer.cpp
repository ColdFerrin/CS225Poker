#include "HumanPlayer.h"
#include <iostream>

using namespace std;

int HumanPlayer::makeDecision()
{
	cout << "Your options are to ";
	if (options[0])
	{
		cout << "0 Check, ";
	}
	if (options[1])
	{
		cout << "1 Bet, ";
	}
	if (options[2])
	{
		cout << "2 Call, ";
	}
	if (options[3])
	{
		cout << "3 Raise, ";
	}
	if (options[4])
	{
		cout << "4 All in, ";
	}
	if (options[5])
	{
		cout << "or 5 Fold" << endl;
	}
	cout << "Please type the number for your desired action:";
	int chosenAction = 0;
	cin >> chosenAction;
	return chosenAction;
}

HumanPlayer::HumanPlayer(int position) : Player(position)
{
}


HumanPlayer::~HumanPlayer()
{
}
