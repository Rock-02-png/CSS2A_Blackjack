#pragma once
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hand
{
protected:
	vector <Card> cards; // Stores the player's or dealer's hand
public:
	void addCard(Card); // Add a card to the hand
	void clear(); // Clear the hand
	vector <Card> getCards(); // Return all cards
	int getTotalValue(); // Get total value of the hand
	bool hasBlackJack(); // Check for Blackjack
	bool isBust(); // Check is hand exceeds 21
};