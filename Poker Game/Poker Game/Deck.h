#pragma once

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
    int deckPosition;
    CARD cardStack[52];
public:
    Deck();
    ~Deck();
    CARD dealCard();
};

#endif // !DECK_H
