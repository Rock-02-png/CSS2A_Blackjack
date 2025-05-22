#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Person.h"


class Game
{
private:
	Deck deck;
	Player player;
	Dealer dealer;
	double bet;
	const int cardWidth = 14;
	int roundCount = 0;

	void takeBet();
	void dealInitalCards();
	void playerTurn();
	void dealerTurn();
	
	void determineOutcome();
	void checkDeck(); // check if decks low and reshuffles if under half 

	//card pictures
	void pCardBox(const Card& card) const;
	void printHand(const string& name, const vector<Card>& hand, int totalValue, bool hideFirst = false) const; 
	// bool is to hide the dealers first card otherwise we show it, all other values are info on the cards
public:
	Game();
	void play();
};

