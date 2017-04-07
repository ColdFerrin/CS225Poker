#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include "Dealer.h"
#include "HumanPlayer.h"
#include "Results.h"

class Table
{
private:
	int numberOfPlayers;
	int humanPlayers;
	int aiPlayers;
	int dealerPosition;
	int playAgain;
	Dealer dealer;
	Player* playersAtTable[9];
	CARD burnCards[3];
	CARD tableCards[5];
	void displayTable();
	bool runAgain();
	Results* results;
	Display display;
public:
	void playGame();
    Table();
    ~Table();
};

#endif //TABLE_H
