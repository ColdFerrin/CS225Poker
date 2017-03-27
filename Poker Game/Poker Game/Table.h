#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <cstdlib>
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
	void displaySuit(int);
	void displaySymbol(int,int);
	void displayTable();
	bool runAgain();
public:
	void playGame();
    Table();
    ~Table();
};

#endif //TABLE_H