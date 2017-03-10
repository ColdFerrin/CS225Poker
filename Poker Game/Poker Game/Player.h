#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player
{
private:
	CARD hand[2];
	int cardsRecived;
public:
	virtual int makeDecision() = 0;
	void collectCard(CARD);
	int cardsInHand();
	void clearHand();
	Player();
	~Player();
};

#endif // !PLAYER_H