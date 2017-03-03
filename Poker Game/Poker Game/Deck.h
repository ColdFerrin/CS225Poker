#pragma once

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
    int deckPosition;
    CARD deck[52];
public:
    Deck();
    ~Deck();
    CARD getCard();
    void burnCard();
};

#endif // !DECK_H
