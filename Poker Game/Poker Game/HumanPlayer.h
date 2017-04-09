/***********************************************************************************
*
* By: Ferrin Katz      
*
***********************************************************************************/  


#pragma once

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Display.h"

class HumanPlayer : public Player
{
private:
	Display display;
public:
	void displayHand();
	int makeDecision();
	HumanPlayer();
	~HumanPlayer();
};
#endif // !HUMANPLAYER_H
