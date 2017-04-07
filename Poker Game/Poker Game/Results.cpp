#include "Results.h"

using namespace std;

Results::Results(int numberOfPlayers)
{
	hasNotFolded = new bool[numberOfPlayers];
	winningHand = new int[numberOfPlayers];
	winningCard = new int[numberOfPlayers];
	secondWinningCard = new int[numberOfPlayers];
	thirdWinningCard = new int[numberOfPlayers];
	fourthWinningCard = new int[numberOfPlayers];
	fifthWinningCard = new int[numberOfPlayers];
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
					secondWinningCard[tablePosition] = cardStack[flushMoving - 1].rank;
                                        thirdWinningCard[tablePosition] = cardStack[flushMoving - 2].rank;
                                        fourthWinningCard[tablePosition] = cardStack[flushMoving - 3].rank;
                                        fifthWinningCard[tablePosition] = cardStack[flushMoving - 4].rank;


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
					secondWinningCard[tablePosition] = cardStack[iterator - 1].rank;
					thirdWinningCard[tablePosition] = cardStack[iterator - 2].rank;
					fourthWinningCard[tablePosition] = cardStack[iterator - 3].rank;
					fifthWinningCard[tablePosition] = cardStack[iterator - 4].rank;


				}
			}
		}
		//		if (straightChance >= 4)
		//			isStraight = 1;
		int firstCardSpot, secondCardSpot;
		for (int move = 0; move < 6; move++)                           //Determines all pairs, two pairs, trips, Full House, and Quads
		{
			for (int moving = move + 1; moving < 7; moving++)
			{
				if (cardStack[move].rank == cardStack[moving].rank)
					winDecider++;
				if (winDecider == 7 || winDecider == 6 || winDecider == 3 || winDecider == 2 || winDecider == 1)           //Determines winning card
				{
					winningCard[tablePosition] = cardStack[move].rank;
					firstCardSpot = move;
				}
				if (winDecider == 6 || winDecider == 2)
				{
					secondWinningCard[tablePosition] = cardStack[moving].rank;
					secondCardSpot = moving;
				}
			}
		}
		// If its Full for first check when its trips then pair
		// Set another winning hand for full and two pair
			
											//Determines the rank of cards some posses
		if (isStraight == 1 && isFlush == 1 && cardStack[0].rank == 14)         //Royal Flush 
			winningHand[tablePosition] = 9;
		else if (isStraight == 1 && isFlush == 1)				//Straight Flush
			winningHand[tablePosition] = 8;
		else if (winDecider == 7)						//Quads
		{
			winningHand[tablePosition] = 7;
			if(winningCard[tablePosition] == cardStack[0].rank)				//Quads where first Position is the start of the Quads
			{
				secondWinningCard[tablePosition] = cardStack[0].rank;
				thirdWinningCard[tablePosition] = cardStack[0].rank;
				fourthWinningCard[tablePosition] = cardStack[0].rank;
				fifthWinningCard[tablePosition] = cardStack[4].rank;
			}
			else if(winningCard[tablePosition] == cardStack[1].rank)                     //Quads where second Position is the start of the Quads
			{
			        secondWinningCard[tablePosition] = cardStack[1].rank;
                                thirdWinningCard[tablePosition] = cardStack[1].rank; 
                                fourthWinningCard[tablePosition] = cardStack[1].rank;
                                fifthWinningCard[tablePosition] = cardStack[0].rank; 
			}
			else if(winningCard[tablePosition] == cardStack[2].rank)                     //Quads where first Position is the start of the Quads
			{
                                secondWinningCard[tablePosition] = cardStack[2].rank;
                                thirdWinningCard[tablePosition] = cardStack[2].rank; 
                                fourthWinningCard[tablePosition] = cardStack[2].rank;
                                fifthWinningCard[tablePosition] = cardStack[0].rank; 
			}
                        else if(winningCard[tablePosition] == cardStack[3].rank)                     //Quads where first Position is the start of the Quads             
                        {
                                secondWinningCard[tablePosition] = cardStack[3].rank;
                                thirdWinningCard[tablePosition] = cardStack[3].rank;
                                fourthWinningCard[tablePosition] = cardStack[3].rank;
                                fifthWinningCard[tablePosition] = cardStack[0].rank;
                        }
		}
		else if (winDecider == 6)                                                       //Full House
		{
			winningHand[tablePosition] = 6;
			if(winningCard[tablePosition] == cardStack[0].rank)                          //First card Trips
			{
				if(secondWinningCard[tablePosition] == cardStack[3].rank)            //Fourth & Fifth card pair
				{
                                	secondWinningCard[tablePosition] = cardStack[0].rank;
                                	thirdWinningCard[tablePosition] = cardStack[0].rank;
                                	fourthWinningCard[tablePosition] = cardStack[3].rank;
                                	fifthWinningCard[tablePosition] = cardStack[3].rank;
				}
				else if(secondWinningCard[tablePosition] ==  cardStack[4].rank)      //Fifth & Sixth Card pair
				{
	                                secondWinningCard[tablePosition] = cardStack[0].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                	fourthWinningCard[tablePosition] = cardStack[4].rank;
                                	fifthWinningCard[tablePosition] = cardStack[4].rank;
				}
				else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair
				{
        	                        secondWinningCard[tablePosition] = cardStack[0].rank;
	                                thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[5].rank;
                                        fifthWinningCard[tablePosition] = cardStack[5].rank;
				}
			}			                                   
			else if(winningCard[tablePosition] == cardStack[1].rank)                     //Second Card Trips                             
                        {        
                                if(secondWinningCard[tablePosition] ==  cardStack[4].rank)          //Fifth & Sixth Card Pair                         
                                {
        	                        secondWinningCard[tablePosition] = cardStack[1].rank;
	                                thirdWinningCard[tablePosition] = cardStack[1].rank;
                                        fourthWinningCard[tablePosition] = cardStack[4].rank;
                                        fifthWinningCard[tablePosition] = cardStack[4].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair                              
                                {
	                                secondWinningCard[tablePosition] = cardStack[1].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[1].rank;
                                        fourthWinningCard[tablePosition] = cardStack[5].rank;
                                        fifthWinningCard[tablePosition] = cardStack[5].rank;
                                }
                        }
			else if(winningCard[tablePosition] == cardStack[2].rank)                     //Third Card Trips
			{       
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second Card Pair                                                   
                                {
                  	        	secondWinningCard[tablePosition] = cardStack[2].rank;
                        	        thirdWinningCard[tablePosition] = cardStack[2].rank;   
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair                              
                                {
                           	        secondWinningCard[tablePosition] = cardStack[2].rank;
                          	        thirdWinningCard[tablePosition] = cardStack[2].rank;  
                                        fourthWinningCard[tablePosition] = cardStack[5].rank;
                                        fifthWinningCard[tablePosition] = cardStack[5].rank;
                                }
                        }
			else if(winningCard[tablePosition] == cardStack[3].rank)                     //Fourth Card Trips
                        {
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second card Pair                                              
                                {
	                                secondWinningCard[tablePosition] = cardStack[3].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[3].rank;
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[1].rank)     //Second & Third card Pair
                                {
	                                secondWinningCard[tablePosition] = cardStack[3].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[3].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[1].rank;
                                }
                        }
                        else if(winningCard[tablePosition] == cardStack[4].rank)                     //Fifth Card Trips
                        {
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second Card Pair
                                {
	                                secondWinningCard[tablePosition] = cardStack[4].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[4].rank;
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[1].rank)     //Second & Third Card Pair
                                {
	                                secondWinningCard[tablePosition] = cardStack[4].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[4].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[1].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[2].rank)     //Third & Fourth Card Pair
                                {
	                                secondWinningCard[tablePosition] = cardStack[4].rank;
        	                        thirdWinningCard[tablePosition] = cardStack[4].rank;
                                        fourthWinningCard[tablePosition] = cardStack[2].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                        }      
		}
		else if (isFlush == 1)
			winningHand[tablePosition] = 5;
		else if (isStraight == 1)
			winningHand[tablePosition] = 4;
		else if (winDecider == 3)
		{
			winningHand[tablePosition] = 3;
			if(winningCard[tablePosition] == cardStack[0].rank)                          //First Card Trips
                        {
                                secondWinningCard[tablePosition] = cardStack[0].rank;
                                thirdWinningCard[tablePosition] = cardStack[0].rank;
                                fourthWinningCard[tablePosition] = cardStack[3].rank;
				fifthWinningCard[tablePosition] = cardStack[4].rank;
			}
			else if(winningCard[tablePosition] ==  cardStack[1].rank)      		     //Second Card Trips
                        {
                        	secondWinningCard[tablePosition] = cardStack[1].rank;
                                thirdWinningCard[tablePosition] = cardStack[1].rank;
                                fourthWinningCard[tablePosition] = cardStack[0].rank;
                                fifthWinningCard[tablePosition] = cardStack[4].rank;
                        }
                        else if(secondWinningCard[tablePosition] ==  cardStack[2].rank)              //Third Card Trips
                        {
                        	secondWinningCard[tablePosition] = cardStack[2].rank;
                                thirdWinningCard[tablePosition] = cardStack[2].rank;
                                fourthWinningCard[tablePosition] = cardStack[0].rank;
                                fifthWinningCard[tablePosition] = cardStack[1].rank;
                        }
                        else if(winningCard[tablePosition] == cardStack[3].rank)                     //Fourth Card Trips
                        {
                        	secondWinningCard[tablePosition] = cardStack[3].rank;
                        	thirdWinningCard[tablePosition] = cardStack[3].rank;
                                fourthWinningCard[tablePosition] = cardStack[0].rank;
                                fifthWinningCard[tablePosition] = cardStack[1].rank;
                        }
                        else if(secondWinningCard[tablePosition] ==  cardStack[4].rank)              //Fifth Cart Trips
                        {
                        	secondWinningCard[tablePosition] = cardStack[4].rank;
                                thirdWinningCard[tablePosition] = cardStack[4].rank;
                                fourthWinningCard[tablePosition] = cardStack[0].rank;
                                fifthWinningCard[tablePosition] = cardStack[1].rank;
                        }
		}
		else if (winDecider == 2)
		{
			winningHand[tablePosition] = 2;
                        if(winningCard[tablePosition] == cardStack[0].rank)                          //First card Pair
                        {
                                if(secondWinningCard[tablePosition] == cardStack[2].rank)            //Third & Fourth card pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[0].rank;
                                        thirdWinningCard[tablePosition] = cardStack[2].rank;
                                        fourthWinningCard[tablePosition] = cardStack[2].rank;
                                        fifthWinningCard[tablePosition] = cardStack[4].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[3].rank)      //Fourth & Fifth Card pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[0].rank;
                                        thirdWinningCard[tablePosition] = cardStack[3].rank;
                                        fourthWinningCard[tablePosition] = cardStack[3].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[4].rank)     //Fifth & Sixth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[0].rank;
                                        thirdWinningCard[tablePosition] = cardStack[4].rank;
                                        fourthWinningCard[tablePosition] = cardStack[4].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[0].rank;
                                        thirdWinningCard[tablePosition] = cardStack[5].rank;
                                        fourthWinningCard[tablePosition] = cardStack[5].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }

                        }
                        else if(winningCard[tablePosition] == cardStack[1].rank)                    //Second Card Pair
                        {
                                if(secondWinningCard[tablePosition] ==  cardStack[3].rank)          //Fourth & Fifth Card Pair 
                                {
                                        secondWinningCard[tablePosition] = cardStack[1].rank;
                                        thirdWinningCard[tablePosition] = cardStack[3].rank;
                                        fourthWinningCard[tablePosition] = cardStack[3].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[4].rank)     //Sixth & Seventh Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[1].rank;
                                        thirdWinningCard[tablePosition] = cardStack[4].rank;
                                        fourthWinningCard[tablePosition] = cardStack[4].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                        }
                        else if(winningCard[tablePosition] == cardStack[2].rank)                    //Third Card Pair  
                        {
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[2].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[4].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[4].rank)     //Fifth & Sixth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[2].rank;
                                        thirdWinningCard[tablePosition] = cardStack[4].rank;
                                        fourthWinningCard[tablePosition] = cardStack[4].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair  
                                {
                                        secondWinningCard[tablePosition] = cardStack[2].rank;
                                        thirdWinningCard[tablePosition] = cardStack[5].rank;
                                        fourthWinningCard[tablePosition] = cardStack[5].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
    			}
                        else if(winningCard[tablePosition] == cardStack[3].rank)                    //Fourth Card Pair   
                        {
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[3].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[1].rank)     //Second & Third Card Pair  
                                {
                                        secondWinningCard[tablePosition] = cardStack[3].rank;
                                        thirdWinningCard[tablePosition] = cardStack[1].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair                  
                                {
                                        secondWinningCard[tablePosition] = cardStack[3].rank;
                                        thirdWinningCard[tablePosition] = cardStack[5].rank;
                                        fourthWinningCard[tablePosition] = cardStack[5].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                        }
                        else if(winningCard[tablePosition] == cardStack[4].rank)                    //Fifth Card Pair        
                        {        
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[4].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[1].rank)     //Second & Third Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[3].rank;
                                        thirdWinningCard[tablePosition] = cardStack[1].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[2].rank)     //Third & Fourth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[3].rank;                
                                        thirdWinningCard[tablePosition] = cardStack[2].rank;
                                        fourthWinningCard[tablePosition] = cardStack[2].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                        }
                        else if(winningCard[tablePosition] == cardStack[5].rank)                    //Sixth Card Pair        
                        {        
                                if(secondWinningCard[tablePosition] ==  cardStack[0].rank)          //First & Second Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[5].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[0].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[1].rank)     //Second & Third Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[5].rank;
                                        thirdWinningCard[tablePosition] = cardStack[1].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[2].rank)     //Third & Fourth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[5].rank;                
                                        thirdWinningCard[tablePosition] = cardStack[2].rank;
                                        fourthWinningCard[tablePosition] = cardStack[2].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[3].rank)     //Fourth & Fifth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[5].rank;
                                        thirdWinningCard[tablePosition] = cardStack[3].rank;
                                        fourthWinningCard[tablePosition] = cardStack[3].rank;
                                        fifthWinningCard[tablePosition] = cardStack[0].rank;
                                }
                        }
		}
		else if (winDecider == 1)
		{
				winningHand[tablePosition] = 1;
                                if(winningCard[tablePosition] == cardStack[0].rank)		    //First & Second Card Pair
				{
                                        secondWinningCard[tablePosition] = cardStack[0].rank;
                                        thirdWinningCard[tablePosition] = cardStack[2].rank;
                                        fourthWinningCard[tablePosition] = cardStack[3].rank; 
                                        fifthWinningCard[tablePosition] = cardStack[4].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[1].rank)     //Second & Third Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[1].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[3].rank;
                                        fifthWinningCard[tablePosition] = cardStack[4].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[2].rank)     //Third & Fourth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[2].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[4].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[3].rank)     //Fourth & Fifth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[3].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[4].rank)     //Fifth & Sixth Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[4].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
                                else if(secondWinningCard[tablePosition] ==  cardStack[5].rank)     //Sixth & Seventh Card Pair
                                {
                                        secondWinningCard[tablePosition] = cardStack[5].rank;
                                        thirdWinningCard[tablePosition] = cardStack[0].rank;
                                        fourthWinningCard[tablePosition] = cardStack[1].rank;
                                        fifthWinningCard[tablePosition] = cardStack[2].rank;
                                }
		}
		else                                                   //To return high card if needed
		{
			winningCard[tablePosition] = cardStack[0].rank;
			secondWinningCard[tablePosition] = cardStack[1].rank;
                        thirdWinningCard[tablePosition] = cardStack[2].rank; 
                        fourthWinningCard[tablePosition] = cardStack[3].rank;
                        fifthWinningCard[tablePosition] = cardStack[4].rank;
			winningHand[tablePosition] = 0;
		}
	}
}

void Results::printResultsToFile()
{
	fstream fptr("HandHistory.txt", ios::out | ios::app);

	fptr << "The table was : "
		<< display.symbolToFile(tableCards[0]) << display.suitToFile(tableCards[0]) << " "
		<< display.symbolToFile(tableCards[1]) << display.suitToFile(tableCards[1]) << " "
		<< display.symbolToFile(tableCards[2]) << display.suitToFile(tableCards[2]) << " "
		<< display.symbolToFile(tableCards[3]) << display.suitToFile(tableCards[3]) << " "
		<< display.symbolToFile(tableCards[4]) << display.suitToFile(tableCards[4]) << endl;

	fptr << "The hands were | ";
	for (int iterator = 0; iterator < numberOfPlayers; iterator++)
	{
		for (int currentCard = 0; currentCard < 1; currentCard++)
		{
			fptr << display.symbolToFile(hands[iterator][currentCard]) << display.suitToFile(hands[iterator][currentCard]) << " ";
		}
		fptr << "| ";
	}
	fptr << endl;

	fptr.close();
}


void Results::getWinner()                                                // To decide who has the winning had
{
	for (int iterator = 0; iterator < numberOfPlayers; iterator++)
	{
		decideStrength(iterator);
	}
	int currentWinner = 0;
        currentlyChopped = 0;
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
				else if (secondWinningCard[currentWinner] == secondWinningCard[iterator])
				{
					if (thirdWinningCard[currentWinner] > thirdWinningCard[iterator])
						currentWinner = currentWinner;
					else if (thirdWinningCard[currentWinner] < thirdWinningCard[iterator])
						currentWinner = iterator;
					else if (thirdWinningCard[currentWinner] == thirdWinningCard[iterator])
					{
						if (fourthWinningCard[currentWinner] > fourthWinningCard[iterator])
							currentWinner = currentWinner;
						else if (fourthWinningCard[currentWinner] < fourthWinningCard[iterator])
							currentWinner = iterator;
						else if (fourthWinningCard{currentWinner} == fourthWinningCard[iterator])
						{
							if (fifthWinningCard[currentWinner] > fifthWinningCard[iterator])
								currentWinner = currentWinner;
							else if (fifthWinningCard[currentWinner] < fifthWinningCard[iterator])
								currentWinner = iterator;
							else (fifthWinningCard[currentWinner] == fifthWinningCard[iterator])
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
\						}
					}
				}
			}
		}
	}
	printResultsToFile();
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

