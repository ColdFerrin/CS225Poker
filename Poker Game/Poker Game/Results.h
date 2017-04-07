#pragma once

#ifndef RESULTS_H
#define RESULTS_H

using namespace std;

#include<cmath>
#include<iostream>
#include<fstream>
#include "Card.h"
#include "Display.h"

class Results
{
	friend ostream& operator<<(ostream&, Results&);
private:
	int theWinner;
	int* winningHand;
	int* winningCard;
	int* secondWinningCard;
	int* thirdWinningCard;
	int* fourthWinningCard;
	int* fifthWinningCard;
	bool* hasNotFolded;
	int numberOfPlayers;
	CARD tableCards[5];
	CARD hands[9][2];
	void decideStrength(int);
	void printResultsToFile();
	Display display;
public:
	Results(int);
	~Results();
	void winningCheck(int);
	void getWinner();
	void playerFolds(int);
	void recordCard(int, int, CARD);
	void recordTableCard(int, CARD);
};

#endif // RESULTS_H
