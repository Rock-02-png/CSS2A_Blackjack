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
	void addCard(const Card& newCard); // Add a card to the hand
	void clear(); // Clear the hand
	const vector<Card>& getCards()const; // Return all cards
	int getTotalValue()const; // Get total value of the hand
	bool hasBlackJack()const; // Check for Blackjack
	bool isBust() const ; // Check is hand exceeds 21
	
};