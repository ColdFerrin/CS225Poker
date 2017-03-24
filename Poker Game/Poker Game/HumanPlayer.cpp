#include "HumanPlayer.h"
#include <iostream>

using namespace std;

void HumanPlayer::displaySuit(int position)
{
	if (hand[position].rank != 0)
	{
		if (hand[position].suit == Spades)
		{
			cout << SPADE;
		}
		else if (hand[position].suit == Clubs)
		{
			cout << CLUB;
		}
		else if (hand[position].suit == Hearts)
		{
			cout << HEART;
		}
		else if (hand[position].suit == Diamonds)
		{
			cout << DIAMOND;
		}
	}
	else
	{
		cout << " ";
	}
}

void HumanPlayer::displaySymbol(int position, int place)
{
	if (place == 0)
	{
		if (hand[position].rank == 0)
		{
			cout << "  ";
		}
		else if (hand[position].rank == 10)
		{
			cout << "10";
		}
		else if (hand[position].rank == 11)
		{
			cout << "J ";
		}
		else if (hand[position].rank == 12)
		{
			cout << "Q ";
		}
		else if (hand[position].rank == 13)
		{
			cout << "K ";
		}
		else if (hand[position].rank == 14)
		{
			cout << "A ";
		}
		else
		{
			cout << hand[position].rank << " ";
		}
	}
	else if (place == 1)
	{
		if (hand[position].rank == 0)
		{
			cout << "__";
		}
		else if (hand[position].rank == 10)
		{
			cout << "10";
		}
		else if (hand[position].rank == 11)
		{
			cout << "_J";
		}
		else if (hand[position].rank == 12)
		{
			cout << "_Q";
		}
		else if (hand[position].rank == 13)
		{
			cout << "_K";
		}
		else if (hand[position].rank == 14)
		{
			cout << "_A";
		}
		else
		{
			cout << "_" << hand[position].rank;
		}
	}
}

void HumanPlayer::displayHand()
{
	cout << "Your hand is," << endl;
	cout << " __________________________________ " << endl
		 << "|     _________      _________     |" << endl
		<< "|    |";
	displaySymbol(0, 0);
	cout << "       |    |";
	displaySymbol(1, 0);
	cout << "       |    |" << endl;
	cout << "|    |";
	displaySuit(0);
	cout << "        |    |";
	displaySuit(1);
	cout << "        |    |" << endl
		 << "|    |         |    |         |    |" << endl
		 << "|    |    ";
	displaySuit(0);
	cout << "    |    |    ";
	displaySuit(1);
	cout << "    |    |    " << endl
		 << "|    |         |    |         |    |" << endl
		 << "|    |        ";
	displaySuit(0);
	cout << "|    |        ";
	displaySuit(1);
	cout << "|    |        " << endl
		 << "|    |_______";
	displaySymbol(0, 1);
	cout << "|    |_______";
	displaySymbol(1, 1);
	cout << "|    |" << endl
		 << "|__________________________________|" << endl;
}

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

HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}
