#include "HumanPlayer.h"
#include <iostream>

using namespace std;

void HumanPlayer::displayHand()
{
	cout << "Your hand is,"
		<< endl
		<< " __________________________________ "
		<< endl
		<< "|     _________      _________     |"
		<< endl
		<< "|    |"
		<< display.symbol(0, hand[0])
		<< "       |    |"
		<< display.symbol(0, hand[1])
		<< "       |    |"
		<< endl
		<< "|    |"
		<< display.suit(hand[0])
		<< "        |    |"
		<< display.suit(hand[1])
		<< "        |    |"
		<< endl
		<< "|    |         |    |         |    |"
		<< endl
		<< "|    |    "
		<< display.suit(hand[0])
		<< "    |    |    "
		<< display.suit(hand[1])
		<< "    |    |    "
		<< endl
		<< "|    |         |    |         |    |"
		<< endl
		<< "|    |        "
		<< display.suit(hand[0])
		<< "|    |        "
		<< display.suit(hand[1])
		<< "|    |        "
		<< endl
		<< "|    |_______"
		<< display.symbol(1, hand[0])
		<< "|    |_______"
		<< display.symbol(1, hand[1])
		<< "|    |" 
		<< endl
		<< "|__________________________________|" 
		<< endl;
}

int HumanPlayer::makeDecision()
{
	
	const string ERR = "This is not a valid data type try again.";
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
	if (!cin)
	{
		throw(ERR);
	}
	else if (chosenAction < 0 || chosenAction > 5 || options[chosenAction] == false)
	{
		throw(chosenAction);
	}
	return chosenAction;
}

HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}
