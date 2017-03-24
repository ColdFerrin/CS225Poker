#pragma once

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{
private:
	void displaySuit(int);
	void displaySymbol(int, int);
public:
	void displayHand();
	int makeDecision();
	HumanPlayer();
	~HumanPlayer();
};
#endif // !HUMANPLAYER_H
