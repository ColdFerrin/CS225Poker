#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//#include "Results.h"

enum Suit
{
	Spades, Hearts, Clubs, Diamonds
};

struct CARD
{
	int suit;
	int rank;
};

class Deck
{
private:
    int deckPosition;
//    CARD cardStack[52];
public:
//    Deck();
//    ~Deck();
    CARD dealCard();
};

class Results:public Deck 
{
  private:
    int theWinner;
  public:
//    Results();
    int decider();
    CARD display();
};

int Results::decider() 
{
  CARD cardStack[52];
  int hand[4][13]= {0};
  int Hupla=0;
//  for(int transport=0; transport<5; transport++)
//  {
//    srand(time(NULL));
//    int rank = rand()%4;
//    cardStack[transport].suit = suit;
//    cardStack[transport].rank = rank; 
    cardStack[0].rank = 1;
    cardStack[1].rank = 1; 
    cardStack[2].rank = 1; 
    cardStack[3].rank = 1; 
    cardStack[4].rank = 2; 
  //  cout << cardStack[transport].rank << endl;
//  }

  int temp, flag = 1;
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
  int pook = 1;
  for(int change = 0; change <5; change++)                      //Checks for Straights
  {
    if(cardStack[change].rank - cardStack[pook].rank == 1)
      straightChance++;
    pook++;
  }
  cout <<"STRAIGHT" << straightChance << endl;
  if(straightChance == 4)
    return 4;
    
  for(int move = 0; move<5; move++)
  {
    for(int moving = move+1; moving <5; moving++)
    {
      if(cardStack[move].rank == cardStack[moving].rank)
        Hupla++;
    }
  }

  cout << "HUla" << Hupla << endl;
  if (Hupla == 6)
    return 7;
  if (Hupla == 4)
    return 6;
  else if (Hupla == 3)
    return 3;
  else if (Hupla == 2)
    return 2;
  else if(Hupla ==1)
    return 1;
  else
    {
    int Point = 0;
    int * bowtie;

    bowtie = &Point;
    for(int changing = 0; changing <5; changing++)
    {
      if(cardStack[changing].rank > Point)
      {     
        Point = cardStack[changing].rank;
      }
    }
    return 0;
    }
}



int main()
{
  int lol;
  Results w;
  lol = w.decider();
  cout << "LOL" << lol << endl;
  if(lol == 9)
    cout << "Royal Flush" << endl;
  else if(lol == 8)
    cout << "Straight Flush" << endl;
  else if(lol == 7)
    cout << "Four of a kind" << endl;
  else if(lol == 6)
    cout << "Full House" << endl;   
  else if(lol == 5)
    cout << "Flush" << endl;
  else if(lol == 4)
    cout <<"Straight" << endl;
  else if (lol == 3)
    cout <<"Three of a kind" << endl;
  else if(lol == 2)
    cout <<" Two Pair" << endl;
  else if(lol == 1)
    cout <<" Pair" << endl;
  else
    cout << "High Card " <<  endl;
  
}

