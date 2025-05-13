#pragma once
#include "Person.h"
#include "Deck.h"
#include <string>
#include <iostream>
using namespace std;

class Dealer : public Person
{
public:
	Dealer(); 
	bool shouldHit(); // Determines whether dealer should hit or stand
	void playTurn(Deck& deck); // Dealer plays automatically
};

