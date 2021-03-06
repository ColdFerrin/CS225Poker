/***********************************************************************************
*
* By: Ferrin Katz      
*
***********************************************************************************/  


#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player
{
protected:
	CARD hand[2];
	int cardsRecived;
	bool options[6]; //Positions in the array for options are 0 for check, 1 for bet, 2 for call, 3 for raise, 4 for all in, 5 for fold
	int tablePosition;
public:
	virtual void displayHand() = 0;
	virtual int makeDecision() = 0; //Standard return codes are 0 for check, 1 for bet, 2 for call, 3 for raise, 4 for all in, 5 for fold
	void collectCard(CARD);
	int cardsInHand();
	void clearHand();
	void setTablePosition(int);
	Player();
	~Player();
};

#endif // !PLAYER_H
