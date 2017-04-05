#pragma once

using namespace std;

#ifndef RESULTS_H
#define RESULTS_H

#include<cmath>
#include<iostream>
#include "Card.h"

class Results
{
	
private:
	int theWinner;
	int* winningHand;
	int* winningCard;
	int* secondWinningCard;
	bool* hasNotFolded;
	int numberOfPlayers;
	CARD tableCards[5];
	CARD hands[9][2];
	void decideStrength(int);
public:
	Results(int);
	~Results();
	void winningCheck(int);
	int getWinner();
	void playerFolds(int);
	void recordCard(int, int, CARD);
	void recordTableCard(int, CARD);
	//friend ostream& operator<<(ostream&, Results&);
};

#endif // RESULTS_H
