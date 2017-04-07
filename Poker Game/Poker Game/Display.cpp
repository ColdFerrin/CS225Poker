#include "Display.h"

string Display::suit(CARD card)
{
	if (card.rank != 0)
	{
		if (card.suit == Spades)
		{
			return SPADE;
		}
		else if (card.suit == Clubs)
		{
			return CLUB;
		}
		else if (card.suit == Hearts)
		{
			return HEART;
		}
		else if (card.suit == Diamonds)
		{
			return DIAMOND;
		}
		else
		{
			return " ";
		}
	}
	else
	{
		return " ";
	}
}

string Display::symbol(int place, CARD card)
{
	if (place == 0)
	{
		if (card.rank == 0)
		{
			return "  ";
		}
		else if (card.rank == 10)
		{
			return "10";
		}
		else if (card.rank == 11)
		{
			return "J ";
		}
		else if (card.rank == 12)
		{
			return "Q ";
		}
		else if (card.rank == 13)
		{
			return "K ";
		}
		else if (card.rank == 14)
		{
			return "A ";
		}
		else
		{
			string toReturn = card.rank + " ";
			return toReturn;
		}
	}
	else if (place == 1)
	{
		if (card.rank == 0)
		{
			return "__";
		}
		else if (card.rank == 10)
		{
			return "10";
		}
		else if (card.rank == 11)
		{
			return "_J";
		}
		else if (card.rank == 12)
		{
			return "_Q";
		}
		else if (card.rank == 13)
		{
			return "_K";
		}
		else if (card.rank == 14)
		{
			return "_A";
		}
		else
		{
			string toReturn = "_" + card.rank;
			return toReturn;
		}
	}
}


Display::Display()
{
}


Display::~Display()
{
}
