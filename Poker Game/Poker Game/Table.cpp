#include "Table.h"

using namespace std;

void Table::playGame()
{
	int playAgain;
	for (int iterator = 0; iterator < humanPlayers; iterator++)
	{
		playersAtTable[iterator] = new HumanPlayer;
	}
	for (int iterator = humanPlayers; iterator < numberOfPlayers; iterator++)
	{
		//playersAtTable[iterator] = new aiPlayer; TODO implement ai player to fill this space
	}
	for (int iterator = numberOfPlayers; iterator < 9; iterator++)
	{
		playersAtTable[iterator] = NULL;
	}

	do
	{
		dealer.shuffleDeck;
		//set players table position
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			playersAtTable[iterator]->setTablePosition(currentPosition);
		}
		//deal first Card
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			playersAtTable[currentPosition]->collectCard(dealer.getCard);
		}
		//deal second card
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			playersAtTable[currentPosition]->collectCard(dealer.getCard);
		}
		//ask players for initial action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			int decision = playersAtTable[currentPosition]->makeDecision();
			if (decision = 5)
			{
				playersAtTable[currentPosition]->clearHand;
			}
		}
		burnCards[0] = dealer.getCard;
		tableCards[0] = dealer.getCard;
		tableCards[1] = dealer.getCard;
		tableCards[2] = dealer.getCard;
		//ask player for second action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int decision;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			if (playersAtTable[currentPosition]->cardsInHand == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}
			if (decision = 5)
			{
				playersAtTable[currentPosition]->clearHand;
			}
		}
		burnCards[1] = dealer.getCard;
		tableCards[3] = dealer.getCard;
		//ask player for third action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int decision;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			if (playersAtTable[currentPosition]->cardsInHand == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}
			if (decision = 5)
			{
				playersAtTable[currentPosition]->clearHand;
			}
		}
		burnCards[2] = dealer.getCard;
		tableCards[4] = dealer.getCard;
		//ask player for final action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int decision;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			if (playersAtTable[currentPosition]->cardsInHand == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}
			if (decision = 5)
			{
				playersAtTable[currentPosition]->clearHand;
			}
		}

		char repeatInput = 0;
		bool invalidExitInput = true;
		do
		{
			cout << "Would you like to play another hand(y/n)? ";
			cin >> repeatInput;
			if (repeatInput == 'y' || repeatInput == 'Y')
			{
				playAgain = 1;
				invalidExitInput = false;
			}
			else if (repeatInput == 'N' || repeatInput == 'N')
			{
				playAgain = 0;
				invalidExitInput = false;
			}
		} while (invalidExitInput);

	} while (playAgain);
}

Table::Table()
{
	cout << "How many people will be playing? ";
	cin >> humanPlayers;
	numberOfPlayers = humanPlayers;
}

Table::~Table()
{
}
