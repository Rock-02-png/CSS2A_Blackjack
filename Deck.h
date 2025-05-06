//deck class is a standalone, serves as a manager for the cards 

#pragma once
#include "Card.h"
#include <vector>
#include <string>


class Deck
{

private:
	vector<Card> cards;
public:
	void drawCard();
	void dealCard();
	void shuffle();
	void reset();

};
