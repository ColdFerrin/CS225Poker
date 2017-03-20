/*********************************************************************************************
*
* Created By: Ferrin Katz
* Date Created: 3/1/17
*
*********************************************************************************************/

#include "Deck.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

Deck::Deck()
{
	vector<int> generator;
	deckPosition = 0;
	for (int inputToVector = 0; inputToVector < 52; inputToVector++)
	{
		generator.push_back(inputToVector);
	}

	srand(time(0));
	int totalShuffles = rand() % 15;

	for (int shuffles = 0; shuffles <= totalShuffles; shuffles++)
	{
		srand(time(NULL));
		random_shuffle(generator.begin(), generator.end());
	}

	int iterator = 0;
	for (vector<int>::iterator it = generator.begin(); it != generator.end(); ++it)
	{
		if (*it >= 0 && *it <= 12)
		{
			cardStack[iterator].suit = Spades;
			cardStack[iterator].rank = *it + 2;
		}
		else if (*it >= 13 && *it <= 25)
		{
			cardStack[iterator].suit = Hearts;
			cardStack[iterator].rank = *it - 11;
		}
		else if (*it >= 26 && *it <= 38)
		{
			cardStack[iterator].suit = Clubs;
			cardStack[iterator].rank = *it - 24;
		}
		else if (*it >= 39 && *it <= 51)
		{
			cardStack[iterator].suit = Diamonds;
			cardStack[iterator].rank = *it - 37;
		}

		iterator++;
	}

    cout << "The deck has been shuffled" << endl;
}

Deck::~Deck()
{

}

CARD Deck::dealCard()
{
    CARD temp;

    temp.rank = cardStack[deckPosition].rank;
    temp.suit = cardStack[deckPosition].suit;
    
    deckPosition++;

    return temp;
}