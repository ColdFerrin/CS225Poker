#pragma once
#ifndef RESULTS_H
#define RESULTS_H

#include "Card.h"
#include "Deck.h"
class Results:public Deck
{
  private:
    int theWinner;
  public:
//    Results();
    int decider();
//    ~Results();
};

#endif // RESULTS_H
