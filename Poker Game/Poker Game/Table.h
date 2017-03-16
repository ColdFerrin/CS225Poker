#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
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
	Dealer dealer;
	Player* playersAtTable[9];
	CARD burnCards[3];
	CARD tableCards[5];
public:
	void playGame();
    Table();
    ~Table();
};

#endif //TABLE_H