#pragma once
#ifndef DEALER_H
#define DELAER_H

#include "Deck.h"
class Dealer
{
private:
	Deck* currentDeck;
public:
	void shuffleDeck();
	CARD getCard();
	void showCard(CARD);
	Dealer();
	~Dealer();
};

#endif // !DEALER_H