#include<iostream>
#include "Results.h"

using namespace std;

Results::Results() 
{
	CARD cardStack[7];
	int winDecider = 0;

	int temp;
	for(int i = 0; i < 6; i++)                                   // Ranks in order from greatest to least
	{
		for(int j = i+1; j < 7; j++)
		{
			if (cardStack[i].rank < cardStack[j].rank)               
			{ 
				temp = cardStack[i].rank;             
				cardStack[i].rank = cardStack[j].rank;
				cardStack[j].rank = temp;
			}
		}
	}
	
	for(int transport=0; transport<5; transport++)                //Prints out cards
	{
		cout << cardStack[transport].rank << endl;                 
	}
	
	int flushCheck, isFlush;
	for(int flushMove = 0; flushMove < 7; flushMove++) 
	{
		flushCheck = 0;
		for(int flushMoving = flushMove + 1; flushMoving < 7; flushMoving++) 
		{
			if (cardStack[flushMove].suit == cardStack[flushMoving].suit)
				flushCheck++;
			if(flushCheck == 5)
				isFlush = 1;
		}
	}  
	
	int straightChance = 0;
	int movingStraight = 1;
	int isStraight;
	for(int change = 0; change <7; change++)                      //Checks for Straights
	{
		if(cardStack[change].rank - cardStack[movingStraight].rank == 1)
			straightChance++;
		movingStraight++;
	}
	
	if(straightChance == 4)
		isStraight = 1;
	
	for(int move = 0; move<7; move++)                           //Determines all pairs, two pairs, trips, Full House, and Quads
	{
		for(int moving = move+1; moving <7; moving++)
		{
			if(cardStack[move].rank == cardStack[moving].rank)
				winDecider++;
			if(winDecider == 7 || winDecider == 6 || winDecider == 3 || winDecider == 2 || winDecider == 1)           //Determines winning card
				winningCard = cardStack[move].rank;
			if(winDecider == 6 || winDecider == 2)
				secondWiningCard = cardStack[moving].rank; 
		}
	}
	// If its Full for first check when its trips then pair
	// Set another winning hand for full and two pair
	if (isStraight == 1 && isFlush == 1 && cardStack[0].rank == 14)         //Determines what rank of what someone has 
		winningHand = 9;
	else if (isStraight == 1 && isFlush == 1)
		winningHand = 8;
	else if (winDecider == 6)
		winningHand = 7;
	else if (winDecider == 4)
		winningHand = 6;
	else if (isFlush == 1)
		winningHand = 5;
	else if (isStraight == 1)
		winningHand = 4;
	else if (winDecider == 3)
		winningHand = 3;
	else if (winDecider == 2)
		winningHand = 2;
	else if(winDecider == 1)
		winningHand = 1;
	else                                                   //To return high card if needed
	{
		winningCard = 1;
		for(int highChange = 0; highChange <7; highChange++)
		{
			if(cardStack[highChange].rank > winningCard)
			{     
				winningCard = cardStack[highChange].rank;
				secondWinningCard = cardstack[highChange].rank;
			}
		}
		winningHand = 0;
	}
}

//void Results::winnerCheck()                                                // To decide who has the winning had
//{
//      if(player1 > player2)
//              cout << Player 1 wins" << endl;
//      else if(player1 < player2)
//              cout << PLayer 2 wins" << endl;
//      else if(player1 = player 2)
//      {
//              if(player1.winningCard > player2.winningCard)  
//                      cout << "Player 1 wins" << endl;
//              else if(player1.winningCard < player2.winningCard)  
//                      cout << "Player 2 wins" << endl;
//              else if(player1.winningCard == player2.winningCard)  
//              {
//                      if(player1.secondWinningCard > player2.secondWinningCard)  
//                              cout << "Player 1 wins" << endl;
//                      else if(player1.secondWinningCard < player2.secondWinningCard)
//                              cout <<"Player 2 wins" << endl;
//                      else
//                              cout << "Chop Pot" << endl;
//              }
//      }
//}

void Results::winningCheck()
{
	if(winningHand == 9)
		cout << "Royal Flush" << endl;
	else if(winningHand == 8)
		cout << "Straight Flush" << endl;
	else if(winningHand == 7)
		cout << "Four of a kind" << endl;
	else if(winningHand == 6)
		cout << "Full House" << endl;
	else if(winningHand == 5)
		cout << "Flush" << endl;
	else if(winningHand == 4)
		cout <<"Straight" << endl;
	else if (winningHand == 3)
		cout <<"Three of a kind" << endl;
	else if(winningHand == 2)
		cout <<" Two Pair" << endl;
	else if(winningHand == 1)
		cout <<" Pair" << endl;
	else
		cout << "High Card " <<  endl;
}


