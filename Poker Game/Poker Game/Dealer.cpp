/***********************************************************************************
*
* By: Dustin Tabangcura      
*
***********************************************************************************/  

#include "Dealer.h"
#include<iostream>

using namespace std;
void Dealer::shuffleDeck()
{
	if (currentDeck != NULL)
	{
		delete currentDeck;
	}
	currentDeck = new Deck;
}

CARD Dealer::getCard()
{
	CARD temp = currentDeck->dealCard();
	return temp;
}

void Dealer::showCard(CARD card)
{
}

Dealer::Dealer()
{
	currentDeck = NULL;
}


Dealer::~Dealer()
{
	delete currentDeck;
}
