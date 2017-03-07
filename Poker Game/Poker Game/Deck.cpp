/*********************************************************************************************
*
* Created By: Ferrin Katz
* Date Created: 3/1/17
*
*********************************************************************************************/

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
                cardStack[traverse].rank = rank + 2;
                if (suit == 0)
                {
                    cardStack[traverse].suit = 's';
                }
                else if (suit == 1)
                {
                    cardStack[traverse].suit = 'h';
                }
                else if (suit == 2)
                {
                    cardStack[traverse].suit = 'c';
                }
                else if (suit == 3)
                {
                    cardStack[traverse].suit = 'd';
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

CARD Deck::dealCard()
{
    CARD temp;

    temp.rank = cardStack[deckPosition].rank;
    temp.suit = cardStack[deckPosition].suit;
    
    deckPosition++;

    return temp;
}