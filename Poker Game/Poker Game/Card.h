#pragma once

#ifndef CARD_H
#define CARD_H

typedef struct CARD
{
    char suit;          //Suit is the first letter of the suit name for example s for spades and so on
    int rank;           //Rank is based on numerical value of the card where jack through ace are the values 11 through 14
};

#endif // !CARD_H

