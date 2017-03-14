#include "Dealer.h"
#include<iostream>

void Dealer::createDeck()
{
	currentDeck = new Deck;
	std::cout << "Created Deck" << std::endl;
}

void Dealer::deleteDeck()
{
	delete currentDeck;
	std::cout << "Delete Deck" << std::endl;
}

CARD Dealer::getCard()
{
	CARD temp = currentDeck->dealCard();
	std::cout << "Get card from Deck" << std::endl;
	return temp;
}

Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}
