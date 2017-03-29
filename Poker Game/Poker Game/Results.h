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
	bool* hasFolded;
	CARD tableCards[5];
	CARD hands[9][2];
	void winnerCheck();
public:
	Results(int);
	~Results();
	void decideStrength(int);
	void winningCheck();
	void playerFolds(int);
	void recordCard(int, int, CARD);
};

#endif // RESULTS_H
