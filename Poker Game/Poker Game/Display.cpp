#include "Display.h"

void Display::suit(CARD card)
{
	if (card.rank != 0)
	{
		if (card.suit == Spades)
		{
			cout << SPADE;
		}
		else if (card.suit == Clubs)
		{
			cout << CLUB;
		}
		else if (card.suit == Hearts)
		{
			cout << HEART;
		}
		else if (card.suit == Diamonds)
		{
			cout << DIAMOND;
		}
	}
	else
	{
		cout << " ";
	}
}

void Display::symbol(int place, CARD card)
{
	if (place == 0)
	{
		if (card.rank == 0)
		{
			cout << "  ";
		}
		else if (card.rank == 10)
		{
			cout << "10";
		}
		else if (card.rank == 11)
		{
			cout << "J ";
		}
		else if (card.rank == 12)
		{
			cout << "Q ";
		}
		else if (card.rank == 13)
		{
			cout << "K ";
		}
		else if (card.rank == 14)
		{
			cout << "A ";
		}
		else
		{
			cout << card.rank << " ";
		}
	}
	else if (place == 1)
	{
		if (card.rank == 0)
		{
			cout << "__";
		}
		else if (card.rank == 10)
		{
			cout << "10";
		}
		else if (card.rank == 11)
		{
			cout << "_J";
		}
		else if (card.rank == 12)
		{
			cout << "_Q";
		}
		else if (card.rank == 13)
		{
			cout << "_K";
		}
		else if (card.rank == 14)
		{
			cout << "_A";
		}
		else
		{
			cout << "_" << card.rank;
		}
	}
}

string Display::suitToFile(CARD card)
{
	if (card.suit == Spades)
	{
		return "S";
	}
	else if (card.suit == Clubs)
	{
		return "C";
	}
	else if (card.suit == Hearts)
	{
		return "H";
	}
	else if (card.suit == Diamonds)
	{
		return "D";
	}
	else
	{
		return 0;
	}
}

string Display::symbolToFile(CARD card)
{
	if (card.rank == 10)
	{
		return "10";
	}
	else if (card.rank == 11)
	{
		return "J";
	}
	else if (card.rank == 12)
	{
		return "Q";
	}
	else if (card.rank == 13)
	{
		return "K";
	}
	else if (card.rank == 14)
	{
		return "A";
	}
	else
	{
		string toReturn = to_string((long long int)card.rank);
		return toReturn;
	}
}


Display::Display()
{
}


Display::~Display()
{
}
