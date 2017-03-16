#pragma once

#ifndef CARD_H
#define CARD_H

#if defined(_WIN32) || defined(__MSDOS__)
#define SPADE   "\x06"
#define CLUB    "\x05"
#define HEART   "\x03"
#define DIAMOND "\x04"
#else
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#endif

enum Suit
{
    Spades, Hearts, Clubs, Diamonds
};

typedef struct CARD
{
    Suit suit;          //Suit is the first letter of the suit name for example, s for spades and so on
    int rank;           //Rank is based on numerical value of the card where jack through ace are the values 11 through 14
};

#endif // !CARD_H