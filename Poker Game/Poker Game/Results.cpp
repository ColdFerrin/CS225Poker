#include "Results.h"

using namespace std;

Results::Results(int numberOfPlayers)
{
	hasNotFolded = new bool[numberOfPlayers];
	winningHand = new int[numberOfPlayers];
	winningCard = new int[numberOfPlayers];
	secondWinningCard = new int[numberOfPlayers];
	Results::numberOfPlayers = numberOfPlayers;
}

Results::~Results()
{
	delete hasNotFolded;
	delete winningHand;
}

void Results::decideStrength(int tablePosition)
{
	if (hasNotFolded)
	{
		CARD cardStack[7];
		for (int i = 0; i < 5; i++)
		{
			cardStack[i] = tableCards[i];
		}
		cardStack[5] = hands[tablePosition][0];
		cardStack[6] = hands[tablePosition][1];

		int winDecider = 0;

		CARD temp;
		for (int i = 0; i < 6; i++)                                   // Ranks in order from greatest to least
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (cardStack[i].rank < cardStack[j].rank)
				{
					temp = cardStack[i];
					cardStack[i] = cardStack[j];
					cardStack[j] = temp;
				}
			}
		}

		int flushCheck = 0, isFlush;
		for (int flushMove = 0; flushMove < 6; flushMove++)               //Checks for flush
		{
			flushCheck = 0;
			for (int flushMoving = flushMove + 1; flushMoving < 7; flushMoving++)
			{
				if (cardStack[flushMove].suit == cardStack[flushMoving].suit)
					flushCheck++;
				else
					flushCheck = 0;
				if (flushCheck == 4)
				{
					isFlush = 1;
					winningCard[tablePosition] = cardStack[flushMoving].rank;
				}
			}
		}

		int straightChance = 0;
		int isStraight;
		bool wheelStraight = false;
		if (cardStack[0].rank == 14 && cardStack[6].rank == 2 && (cardStack[5].rank == 3 || cardStack[4].rank == 3 || cardStack[3].rank == 3))
			cardStack[0].rank = 1;
		//		for (int change = 0; change < 6; change++)                      //Checks for Straights
		//		{
		//			if (cardStack[change].rank - cardStack[change + 1].rank == 1)
		//				straightChance++;
		//			else
		//				straightChance = 0;
		//		}
		for (int iterator = 0; iterator < 3; iterator++)
		{
			for (int iterator2 = (iterator + 1); iterator2 < (iterator + 5); iterator2++)
			{
				if (cardStack[iterator].rank - cardStack[iterator2].rank == 1)
					straightChance++;
				else
					straightChance = 0;
				if (straightChance == 4)
				{
					isStraight = 1;
					winningCard[tablePosition] = cardStack[iterator].rank;
				}
			}
		}
		//		if (straightChance >= 4)
		//			isStraight = 1;

		for (int move = 0; move < 6; move++)                           //Determines all pairs, two pairs, trips, Full House, and Quads
		{
			for (int moving = move + 1; moving < 7; moving++)
			{
				if (cardStack[move].rank == cardStack[moving].rank)
					winDecider++;
				if (winDecider == 7 || winDecider == 6 || winDecider == 3 || winDecider == 2 || winDecider == 1)           //Determines winning card
					winningCard[tablePosition] = cardStack[move].rank;
				if (winDecider == 6 || winDecider == 2)
					secondWinningCard[tablePosition] = cardStack[moving].rank;
			}
		}
		// If its Full for first check when its trips then pair
		// Set another winning hand for full and two pair
		if (isStraight == 1 && isFlush == 1 && cardStack[0].rank == 14)         //Determines what rank of what someone has 
			winningHand[tablePosition] = 9;
		else if (isStraight == 1 && isFlush == 1)
			winningHand[tablePosition] = 8;
		else if (winDecider == 6)
			winningHand[tablePosition] = 7;
		else if (winDecider == 4)
			winningHand[tablePosition] = 6;
		else if (isFlush == 1)
			winningHand[tablePosition] = 5;
		else if (isStraight == 1)
			winningHand[tablePosition] = 4;
		else if (winDecider == 3)
			winningHand[tablePosition] = 3;
		else if (winDecider == 2)
			winningHand[tablePosition] = 2;
		else if (winDecider == 1)
			winningHand[tablePosition] = 1;
		else                                                   //To return high card if needed
		{
			winningCard[tablePosition] = cardStack[0].rank;
			secondWinningCard[tablePosition] = cardStack[1].rank;
			winningHand[tablePosition] = 0;
		}
	}
}


void Results::getWinner()                                                // To decide who has the winning had
{
	for (int iterator = 0; iterator < numberOfPlayers; iterator++)
	{
		decideStrength(iterator);
	}
	int currentWinner = 0;
	int currentlyChopped = 0;
	for (int iterator = 1; iterator < numberOfPlayers; iterator++)
	{
		if (winningHand[currentWinner] > winningHand[iterator])
			currentWinner = currentWinner;
		else if (winningHand[currentWinner] < winningHand[iterator])
			currentWinner = iterator;
		else if (winningHand[currentWinner] == winningHand[iterator])
		{
			if (winningCard[currentWinner] > winningCard[iterator])
				currentWinner = currentWinner;
			else if (winningCard[currentWinner] < winningCard[iterator])
				currentWinner = iterator;
			else if (winningCard[currentWinner] == winningCard[iterator])
			{
				if (secondWinningCard[currentWinner] > secondWinningCard[iterator])
					currentWinner = currentWinner;
				else if (secondWinningCard[currentWinner] < secondWinningCard[iterator])
					currentWinner = iterator;
				else
				{
					if (currentlyChopped == 0)
					{
						currentlyChopped = (int)pow(currentWinner, 2) + (int)pow(iterator, 2);
					}
					else if (currentlyChopped != 0)
					{
						currentlyChopped += (int)pow(iterator, 2);
						currentWinner = iterator;
					}
				}
			}
		}
	}
	theWinner = currentWinner + 1;
}

void Results::winningCheck(int tablePosition)
{
	if (winningHand[tablePosition] == 9)
		cout << "Royal Flush" << endl;
	else if (winningHand[tablePosition] == 8)
		cout << "Straight Flush" << endl;
	else if (winningHand[tablePosition] == 7)
		cout << "Four of a kind" << endl;
	else if (winningHand[tablePosition] == 6)
		cout << "Full House" << endl;
	else if (winningHand[tablePosition] == 5)
		cout << "Flush" << endl;
	else if (winningHand[tablePosition] == 4)
		cout << "Straight" << endl;
	else if (winningHand[tablePosition] == 3)
		cout << "Three of a kind" << endl;
	else if (winningHand[tablePosition] == 2)
		cout << " Two Pair" << endl;
	else if (winningHand[tablePosition] == 1)
		cout << " Pair" << endl;
	else
		cout << "High Card " << endl;
}

void Results::playerFolds(int tablePosition)
{
	hasNotFolded[tablePosition] = false;
}

void Results::recordCard(int tablePosition, int cardNumber, CARD card)
{
	hands[tablePosition][cardNumber] = card;
}
void Results::recordTableCard(int position, CARD card)
{
	tableCards[position] = card;
}

ostream& operator<<(ostream& os, Results& current)
{
	os << "The Winner is Player " << current.theWinner << endl << endl;
	return os;
}
