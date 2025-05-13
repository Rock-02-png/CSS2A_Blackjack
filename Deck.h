//deck class serves as a manager for the cards 

#pragma once
#include "Card.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>


class Deck
{
private:
	vector<Card> cards; // Vector to hold the cards
	int currentCard; // Index of the current card to be dealt
public:
	Deck();				  //initialize deck of 52 cards
	Card drawCard();      //returns top card
	void shuffleDeck();
	void reset();		  //resets deck
	bool isEmpty() const; // Check if the deck is empty
};
