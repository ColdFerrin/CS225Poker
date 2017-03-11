#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player
{
protected:
	CARD hand[2];
	int cardsRecived;
	bool options[5]; //Positions in the array for options are 0 for check, 1 for bet, 2 for raise, 3 for all in, 4 for fold
public:
	virtual int makeDecision() = 0; //Standard return codes are 0 for check, 1 for bet, 2 for raise, 3 for all in, 4 for fold
	void collectCard(CARD);
	int cardsInHand();
	void clearHand();
	Player(int);
	~Player();
};

#endif // !PLAYER_H