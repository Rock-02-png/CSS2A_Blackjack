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

	void takeBet();
	void dealInitalCards();
	void playerTurn();
	void dealerTurn();
	void showHands(bool dealerHidden);
	void determineOutcome();
public:
	Game();
	void play();
};

