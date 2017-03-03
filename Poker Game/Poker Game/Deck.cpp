#include "Deck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Deck::Deck()
{
    bool generated[4][13] = { 0 };
    for (int traverse = 0; traverse < 52; traverse++)
    {
        bool isCardValid = 0;
        int suit;
        int rank;
        while (!isCardValid)
        {
            srand(time(NULL));

            rank = rand() % 13;
            suit = rand() % 4;

            if (generated[suit][rank] == 0)
            {
                generated[suit][rank] = 1;
                deck[traverse].rank = rank + 2;
                if (suit == 0)
                {
                    deck[traverse].suit = 's';
                }
                else if (suit == 1)
                {
                    deck[traverse].suit = 'h';
                }
                else if (suit == 2)
                {
                    deck[traverse].suit = 'c';
                }
                else if (suit == 3)
                {
                    deck[traverse].suit = 'd';
                }
                isCardValid = true;
            }
        }
    }

    cout << "The deck has been shuffled" << endl;
}


Deck::~Deck()
{

}

CARD Deck::getCard()
{
    CARD temp;

    temp.rank = deck[deckPosition].rank;
    temp.suit = deck[deckPosition].suit;
    
    deckPosition++;

    return temp;
}

void Deck::burnCard()
{
    deckPosition++;
}
