OBJS = PokerGame.o Table.o Dealer.o HumanPlayer.o Player.o Deck.o
CC= g++
CFLAGS = -c
LFLAGS = -Wall

pokergame: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o PokerGame

PokerGame.o: PokerGame.cpp
		$(CC) $(CFLAGS) PokerGame.cpp
		
Table.o: Table.cpp Table.h
		$(CC) $(CFLAGS) Table.cpp
		
Dealer.o: Dealer.cpp Dealer.h
		$(CC) $(CFLAGS) Dealer.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
		$(CC) $(CFLAGS) HumanPlayer.cpp

Player.o: Player.cpp Player.h
		$(CC) $(CFLAGS) Player.cpp

Deck.o: Deck.cpp Deck.h
		$(CC) $(CFLAGS) Deck.cpp

clean:
		rm -i *.o PokerGame
