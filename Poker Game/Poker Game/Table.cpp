#include "Table.h"

using namespace std;

void Table::displaySuit(int position)
{
	if (tableCards[position].rank != 0)
	{
		if (tableCards[position].suit == Spades)
		{
			cout << SPADE;
		}
		else if (tableCards[position].suit == Clubs)
		{
			cout << CLUB;
		}
		else if (tableCards[position].suit == Hearts)
		{
			cout << HEART;
		}
		else if (tableCards[position].suit == Diamonds)
		{
			cout << DIAMOND;
		}
	}
	else
	{
		cout << " ";
	}
}

void Table::displayTable()
{
#if defined(_WIN32) || defined(__MSDOS__)
	system("cls");
#else
	cout << "\033[2J";
#endif

	char outputSymbol[5] = { 0 };
	for (int iterator = 0; iterator < 5; iterator++)
	{
		if (tableCards[iterator].rank == 0)
		{
			outputSymbol[iterator] = ' ';
		}
		else if (tableCards[iterator].rank == 11)
		{
			outputSymbol[iterator] = 'J';
		}
		else if (tableCards[iterator].rank == 12)
		{
			outputSymbol[iterator] = 'Q';
		}
		else if (tableCards[iterator].rank == 13)
		{
			outputSymbol[iterator] = 'K';
		}
		else if (tableCards[iterator].rank == 14)
		{
			outputSymbol[iterator] = 'A';
		}
		else
		{
			outputSymbol[iterator] = (tableCards[iterator].rank + 48);
		}


	}
	cout << " ______________________________________________________________________________ " << endl
		 << "|     _________      _________      _________      _________      _________    |" << endl
		 << "|    |" << outputSymbol[0] << "        |    |"
		 << outputSymbol[1] << "        |    |"
		 << outputSymbol[2] << "        |    |"
		 << outputSymbol[3] << "        |    |"
		 << outputSymbol[4] << "        |   |" << endl;
	cout << "|    |";
	displaySuit(0);
	cout << "        |    |";
	displaySuit(1);
	cout << "        |    |";
	displaySuit(2);
	cout << "        |    |";
	displaySuit(3);
	cout << "        |    |";
	displaySuit(4);
	cout << "        |   |" << endl
		 << "|    |         |    |         |    |         |    |         |    |         |   |" << endl
		 << "|    |    ";
	displaySuit(0);
	cout << "    |    |    ";
	displaySuit(1);
	cout << "    |    |    ";
	displaySuit(2);
	cout << "    |    |    ";
	displaySuit(3); 
	cout << "    |    |    ";
	displaySuit(4); 
	cout << "    |   |" << endl
		 << "|    |         |    |         |    |         |    |         |    |         |   |" << endl
		 << "|    |        ";
	displaySuit(0);
	cout << "|    |        ";
	displaySuit(1); 
	cout << "|    |        ";
	displaySuit(2); 
	cout << "|    |        ";
	displaySuit(3); 
	cout << "|    |        ";
	displaySuit(4);
	cout << "|   |" << endl
		 << "|    |________"<< outputSymbol[0] <<"|    |________"
		 << outputSymbol[1] <<"|    |________"
		 << outputSymbol[2] <<"|    |________"
		 << outputSymbol[3] <<"|    |________"
		 << outputSymbol[4] <<"|   |" << endl
		 << "|______________________________________________________________________________|" << endl;
}

void Table::playGame()
{
	int playAgain = 0;
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
		dealer.shuffleDeck();
		//zero out table cards
		for (int iterator = 0; iterator < 5; iterator++)
		{
			tableCards[iterator].rank = 0;
		}
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
			playersAtTable[currentPosition]->collectCard(dealer.getCard());
		}
		//deal second card
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			playersAtTable[currentPosition]->collectCard(dealer.getCard());
		}
		//ask players for initial action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			int decision = playersAtTable[currentPosition]->makeDecision();
			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
			}
		}
		burnCards[0] = dealer.getCard();
		tableCards[0] = dealer.getCard();
		tableCards[1] = dealer.getCard();
		tableCards[2] = dealer.getCard();
		displayTable();
		//ask player for second action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int decision;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			if ((int)playersAtTable[currentPosition]->cardsInHand() == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}
			else
			{
				decision = 5;
			}

			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
			}
		}
		burnCards[1] = dealer.getCard();
		tableCards[3] = dealer.getCard();
		//ask player for third action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int decision;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			if ((int) playersAtTable[currentPosition]->cardsInHand() == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}
			else
			{
				decision = 5;
			}

			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
			}
		}
		burnCards[2] = dealer.getCard();
		tableCards[4] = dealer.getCard();
		//ask player for final action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int decision;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			if ((int) playersAtTable[currentPosition]->cardsInHand() == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}
			else
			{
				decision = 5;
			}

			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
			}
		}

		char repeatInput = 0;
		bool invalidExitInput = true;
		do
		{
			cout << "Would you like to play another hand(y/n)? ";
			cin >> repeatInput;
			if (tolower(repeatInput) == 'y')
			{
				playAgain = 1;
				invalidExitInput = false;
				for (int iterator = 0; iterator < numberOfPlayers; iterator++)
				{
					playersAtTable[iterator]->clearHand();
				}
				dealerPosition++;
			}
			else if (tolower(repeatInput) == 'n')
			{
				playAgain = 0;
				invalidExitInput = false;
				delete[] playersAtTable;
			}
		} while (invalidExitInput);

	} while (playAgain);
}

Table::Table()
{
	cout << "How many people will be playing? ";
	cin >> humanPlayers;
	numberOfPlayers = humanPlayers;
	dealerPosition = 0;
}

Table::~Table()
{
}
