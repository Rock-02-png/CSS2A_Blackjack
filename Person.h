#pragma once
#include "Person.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
protected:
	vector <Card> cards; // Stores the player's or dealer's Person
public:
	//overloads
	Person& operator+= (const Card& card);
	friend bool operator>(const Person& a, const Person& b);
	friend bool operator<(const Person& a, const Person& b);
	friend bool operator==(const Person& a, const Person& b);
	friend bool operator!=(const Person& a, const Person& b);
	friend bool operator<=(const Person& a, const Person& b);
	friend bool operator>=(const Person& a, const Person& b);

	void addCard(const Card& newCard); // Add a card to the Person
	void clear(); // Clear the Person
	const vector<Card>& getCards()const; // Return all cards
	int getTotalValue()const; // Get total value of the Person
	bool hasBlackJack()const; // Check for Blackjack
	bool isBust() const ; // Check is Person exceeds 21
	
};