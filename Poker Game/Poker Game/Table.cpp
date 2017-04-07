#include "Table.h"

using namespace std;

void Table::displayTable()
{
#if defined(_WIN32) || defined(__MSDOS__)
	system("cls");
#else
	cout << "\033[2J";
#endif


	cout << " _____________________________________________________________________________ " 
		<< endl
		<< "|    _________      _________      _________      _________      _________    |" 
		<< endl
		<< "|   |"
		<< display.symbol(0, tableCards[0])
		<< "       |    |"
		<< display.symbol(0, tableCards[1])
		<< "       |    |"
		<< display.symbol(0, tableCards[2])
		<< "       |    |"
		<< display.symbol(0, tableCards[3])
		<< "       |    |"
		<< display.symbol(0, tableCards[4])
		<< "       |   |" 
		<< endl
		<< "|   |"
		<< display.suit(tableCards[0])
		<< "        |    |"
		<< display.suit(tableCards[1])
		<< "        |    |"
		<< display.suit(tableCards[2])
		<< "        |    |"
		<< display.suit(tableCards[3])
		<< "        |    |"
		<< display.suit(tableCards[4])
		<< "        |   |" 
		<< endl
		<< "|   |         |    |         |    |         |    |         |    |         |   |" 
		<< endl
		<< "|   |    "
		<< display.suit(tableCards[0])
		<< "    |    |    "
		<< display.suit(tableCards[1])
		<< "    |    |    "
		<< display.suit(tableCards[2])
		<< "    |    |    "
		<< display.suit(tableCards[3])
		<< "    |    |    "
		<< display.suit(tableCards[4])
		<< "    |   |" 
		<< endl
		<< "|   |         |    |         |    |         |    |         |    |         |   |" 
		<< endl
		<< "|   |        "
		<< display.suit(tableCards[0])
		<< "|    |        "
		<< display.suit(tableCards[0])
		<< "|    |        "
		<< display.suit(tableCards[0]) 
		<< "|    |        "
		<< display.suit(tableCards[0]) 
		<< "|    |        "
		<< display.suit(tableCards[0]) 
		<< "|   |" 
		<< endl
		<< "|   |_______"
		<< display.symbol(1, tableCards[0])
		<< "|    |_______"
		<< display.symbol(1, tableCards[1])
		<< "|    |_______"
		<< display.symbol(1, tableCards[2])
		<< "|    |_______"
		<< display.symbol(1, tableCards[3])
		<< "|    |_______"
		<< display.symbol(1, tableCards[4])
		<< "|   |" 
		<< endl
		<< "|_____________________________________________________________________________|" 
		<< endl;
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
		for (int iterator = 0; iterator < numberOfPlayers; iterator++)
		{
			playersAtTable[iterator]->clearHand();
		}
		dealerPosition++;
		return false;
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

		//ask player for actions
		for (int currentStep = 0; currentStep <= 3; currentStep++)
		{
			for (int iterator = 0; iterator < numberOfPlayers; iterator++)
			{
				displayTable();
				bool invalidDecision = true;
				int decision = 5;
				int currentPosition = (iterator + dealerPosition) % (numberOfPlayers);
				cout << "It is player " << currentPosition + 1 << "'s Turn" << endl << endl;
				playersAtTable[currentPosition]->displayHand();
				if ((int)playersAtTable[currentPosition]->cardsInHand() == 2)
				{
					do
					{
						try
						{
							decision = playersAtTable[currentPosition]->makeDecision();
							invalidDecision = false;
						}
						catch (int& x)
						{
							cout << x << " is not a valid action. Try again." << endl << endl;
						}
						catch (string& err)
						{
							cout << err << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
					} while (invalidDecision);
				}

				if (decision == 5)
				{
					playersAtTable[currentPosition]->clearHand();
					results->playerFolds(currentPosition);
				}
			}

			if (currentStep == 0)
			{
				burnCards[0] = dealer.getCard();
				tableCards[0] = dealer.getCard();
				results->recordTableCard(0, tableCards[0]);
				tableCards[1] = dealer.getCard();
				results->recordTableCard(1, tableCards[1]);
				tableCards[2] = dealer.getCard();
				results->recordTableCard(2, tableCards[2]);
			}
			else if (currentStep == 1)
			{
				burnCards[1] = dealer.getCard();
				tableCards[3] = dealer.getCard();
				results->recordTableCard(3, tableCards[3]);
			}
			else if (currentStep == 2)
			{
				burnCards[2] = dealer.getCard();
				tableCards[4] = dealer.getCard();
				results->recordTableCard(4, tableCards[4]);
			}
		}

#if defined(_WIN32) || defined(__MSDOS__)
		system("cls");
#else
		cout << "\033[2J";
#endif

		results->getWinner();
		cout << *results;

		char repeatInput = 0;
		bool invalidExitInput = true;
		delete results;
		do
		{
			try
			{
				invalidExitInput = runAgain();
			}
			catch (string& msg)
			{
				cout << msg << endl;
			}
		} while (invalidExitInput);

	} while (playAgain);
}

Table::Table()
{
	const string ERR = "This is not a valid data type.";
	cout << "How many people will be playing? ";
	cin >> humanPlayers;
	if (!cin)
	{
		throw(ERR);
	}
	else if (humanPlayers < 1 || humanPlayers > 9)
	{
		throw(humanPlayers);
	}
	numberOfPlayers = humanPlayers;
	dealerPosition = 0;
}

Table::~Table()
{
}
