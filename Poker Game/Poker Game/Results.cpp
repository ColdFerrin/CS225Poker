#include<iostream>
#include "Results.h"
using namespace std;

int Results::decider() 
{
  CARD cardStack[52];
  int winDecider = 0;
  cardStack[0].rank = 1;
  cardStack[1].rank = 1; 
  cardStack[2].rank = 1; 
  cardStack[3].rank = 1; 
  cardStack[4].rank = 2; 


  int temp;
  for(int i = 0; i < 4; i++)                                   // Ranks in order from greatest to least
  {
    for(int j = i+1; j < 5; j++)
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

  int straightChance = 0;
  int movingStraight = 1;
  for(int change = 0; change <5; change++)                      //Checks for Straights
  {
    if(cardStack[change].rank - cardStack[movingStraight].rank == 1)
      straightChance++;
    movingStraight++;
  }
  cout <<"STRAIGHT" << straightChance << endl;
  if(straightChance == 4)
    return 4;
    
  for(int move = 0; move<5; move++)                           //Determines all pairs, two pairs, trips, Full House, and Quads
  {
    for(int moving = move+1; moving <5; moving++)
    {
      if(cardStack[move].rank == cardStack[moving].rank)
        winDecider++;
    }
  }

  cout << "HUla" << winDecider << endl;
  if (winDecider == 6)
    return 7;
  if (winDecider == 4)
    return 6;
  else if (winDecider == 3)
    return 3;
  else if (winDecider == 2)
    return 2;
  else if(winDecider == 1)
    return 1;
  else                                                   //To return high card if needed
    {
    int highCard = 0;
    for(int highChange = 0; highChange <5; highChange++)
    {
      if(cardStack[highChange].rank > highCard)
      {     
        highCard = cardStack[highChange].rank;
      }
    }
    return 0;
    }
}



int main()
{
  int winnerDecided;
  Results w;
  winnerDecided = w.decider();
  cout << "LOL" << winnerDecided << endl;
  if(winnerDecided == 9)
    cout << "Royal Flush" << endl;
  else if(winnerDecided == 8)
    cout << "Straight Flush" << endl;
  else if(winnerDecided == 7)
    cout << "Four of a kind" << endl;
  else if(winnerDecided == 6)
    cout << "Full House" << endl;   
  else if(winnerDecided == 5)
    cout << "Flush" << endl;
  else if(winnerDecided == 4)
    cout <<"Straight" << endl;
  else if (winnerDecided == 3)
    cout <<"Three of a kind" << endl;
  else if(winnerDecided == 2)
    cout <<" Two Pair" << endl;
  else if(winnerDecided == 1)
    cout <<" Pair" << endl;
  else
    cout << "High Card " <<  endl;
  
}

