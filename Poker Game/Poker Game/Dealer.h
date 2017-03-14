#pragma once
#ifndef DEALER_H
#define DELAER_H

#include "Deck.h"
class Dealer
{
private:
	Deck* currentDeck;
public:
	void createDeck();
	void deleteDeck();
	CARD getCard();
	Dealer();
	~Dealer();
};

#endif // !DEALER_H