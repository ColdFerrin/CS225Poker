#include "Player.h"

void Player::collectCard(CARD newCard)
{
	if (cardsRecived < 2)
	{
		hand[cardsRecived].suit = newCard.suit;
		hand[cardsRecived].rank = newCard.rank;
	}
}

int Player::cardsInHand()
{
	switch (cardsRecived)
	{
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		return 0;
		break;
	}
}

void Player::clearHand()
{
	cardsRecived = 0;
	options[0] = true;
	options[1] = false;
	options[2] = false;
	options[3] = false;
	options[4] = true;
}

Player::Player(int tablePosition)
{
	cardsRecived = 0;
	options[0] = true;
	options[1] = false;
	options[2] = false;
	options[3] = false;
	options[4] = true;
};

Player::~Player()
{
}
