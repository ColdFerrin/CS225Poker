#pragma once

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{
private:
public:
	int makeDecision();
	HumanPlayer();
	~HumanPlayer();
};
#endif // !HUMANPLAYER_H
