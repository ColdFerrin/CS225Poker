/*********************************************************************************************
*
* Created By: Ferrin Katz
* Date Created: 3/1/17
*
*********************************************************************************************/

#pragma once

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
    int deckPosition;
    CARD cardStack[52];
	int myRandom(int);
public:
    Deck();
    ~Deck();
    CARD dealCard();
};

#endif // !DECK_H
