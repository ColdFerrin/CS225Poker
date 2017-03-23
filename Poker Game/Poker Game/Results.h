#pragma once

#ifndef RESULTS_H
#define RESULTS_H

#include "Card.h"

class Results
{
private:
	int theWinner;
	int winningHand;
	int winningCard;
	int secondWinningCard;
public:
	Results();
	void winningCheck();
	void winnerCheck();
};

#endif // RESULTS_H
