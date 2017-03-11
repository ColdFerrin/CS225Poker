#pragma once
#ifndef RESULTS_H
#define RESULTS_H

#include "Card.h"
#include "Deck.h"
class Results: public Deck
{
  private:
    int theWinner;
    int winningHand;
  public:
    Results();
    void winningCheck();
};

#endif // RESULTS_H
