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

void Table::displaySymbol(int position,int place)
{
	if (place == 0)
	{
		if (tableCards[position].rank == 0)
		{
			cout << "  ";
		}
		else if (tableCards[position].rank == 10)
		{
			cout << "10";
		}
		else if (tableCards[position].rank == 11)
		{
			cout << "J ";
		}
		else if (tableCards[position].rank == 12)
		{
			cout << "Q ";
		}
		else if (tableCards[position].rank == 13)
		{
			cout << "K ";
		}
		else if (tableCards[position].rank == 14)
		{
			cout << "A ";
		}
		else
		{
			cout << tableCards[position].rank << " ";
		}
	}
	else if (place == 1)
	{
		if (tableCards[position].rank == 0)
		{
			cout << "__";
		}
		else if (tableCards[position].rank == 10)
		{
			cout << "10";
		}
		else if (tableCards[position].rank == 11)
		{
			cout << "_J";
		}
		else if (tableCards[position].rank == 12)
		{
			cout << "_Q";
		}
		else if (tableCards[position].rank == 13)
		{
			cout << "_K";
		}
		else if (tableCards[position].rank == 14)
		{
			cout << "_A";
		}
		else
		{
			cout << "_" << tableCards[position].rank;
		}
	}
}

void Table::displayTable()
{
#if defined(_WIN32) || defined(__MSDOS__)
	system("cls");
#else
	cout << "\033[2J";
#endif

	
	cout << " _____________________________________________________________________________ " << endl
		 << "|    _________      _________      _________      _________      _________    |" << endl
		 << "|   |";
	displaySymbol(0,0);
	cout << "       |    |";
	displaySymbol(1,0);
	cout << "       |    |";
	displaySymbol(2,0);
	cout << "       |    |";
	displaySymbol(3,0);
	cout << "       |    |";
	displaySymbol(4,0);
	cout << "       |   |" << endl;
	cout << "|   |";
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
		 << "|   |         |    |         |    |         |    |         |    |         |   |" << endl
		 << "|   |    ";
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
		 << "|   |         |    |         |    |         |    |         |    |         |   |" << endl
		 << "|   |        ";
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
		 << "|   |_______";
	displaySymbol(0, 1);
	cout << "|    |_______";
	displaySymbol(1, 1);
	cout << "|    |_______";
	displaySymbol(2, 1);
	cout << "|    |_______";
	displaySymbol(3, 1);
	cout << "|    |_______";
	displaySymbol(4, 1);
	cout << "|   |" << endl
		 << "|_____________________________________________________________________________|" << endl;
}

bool Table::runAgain()
{
	char repeatInput;
	cout << "Would you like to play another hand(y/n)? ";
	cin >> repeatInput;
	const string MSG = "Invalid input.";
	if (tolower(repeatInput) == 'y')
	{
		playAgain = 1;
		return false;
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			playersAtTable[iterator]->clearHand();
		}
		dealerPosition++;
	}
	else if (tolower(repeatInput) == 'n')
	{
		playAgain = 0;
		return false;
		delete[] playersAtTable;
	}
	else
	{
		throw(MSG);
	}
}

void Table::playGame()
{
	playAgain = 0;
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
		results = new Results(numberOfPlayers);
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
			CARD temp = dealer.getCard();
			playersAtTable[currentPosition]->collectCard(temp);
			results->recordCard(currentPosition, 0, temp);
		}
		//deal second card
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			CARD temp = dealer.getCard();
			playersAtTable[currentPosition]->collectCard(temp);
			results->recordCard(currentPosition, 1, temp);
		}
		//ask players for initial action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			cout << "It is player " << currentPosition + 1 << "'s Turn" << endl << endl;
			playersAtTable[currentPosition]->displayHand();
			int decision = playersAtTable[currentPosition]->makeDecision();
			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
				results->playerFolds(currentPosition);
			}
		}
		burnCards[0] = dealer.getCard();
		tableCards[0] = dealer.getCard();
		tableCards[1] = dealer.getCard();
		tableCards[2] = dealer.getCard();
		//ask player for second action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int decision = 5;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			cout << "It is player " << currentPosition + 1 << "'s Turn" << endl << endl;
			playersAtTable[currentPosition]->displayHand();
			if ((int)playersAtTable[currentPosition]->cardsInHand() == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}

			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
				results->playerFolds(currentPosition);
			}
		}
		burnCards[1] = dealer.getCard();
		tableCards[3] = dealer.getCard();
		//ask player for third action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int decision = 5;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			cout << "It is player " << currentPosition + 1 << "'s Turn" << endl << endl;
			playersAtTable[currentPosition]->displayHand();
			if ((int) playersAtTable[currentPosition]->cardsInHand() == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}

			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
				results->playerFolds(currentPosition);
			}
		}
		burnCards[2] = dealer.getCard();
		tableCards[4] = dealer.getCard();
		//ask player for final action
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			displayTable();
			int decision = 5;
			int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
			cout << "It is player " << currentPosition + 1 << "'s Turn" << endl << endl;
			playersAtTable[currentPosition]->displayHand();
			if ((int) playersAtTable[currentPosition]->cardsInHand() == 2)
			{
				decision = playersAtTable[currentPosition]->makeDecision();
			}

			if (decision == 5)
			{
				playersAtTable[currentPosition]->clearHand();
				results->playerFolds(currentPosition);
			}
		}

		char repeatInput = 0;
		bool invalidExitInput = true;
		delete results;
		do
		{
			try
			{
				invalidExitInput = runAgain();
			}
			catch (string msg)
			{
				cout << msg << endl;
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
