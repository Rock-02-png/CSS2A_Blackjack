#include "Card.h"
#include <iostream>
#include <string>


Card::Card() : suit("unknown"), rank(-1), value(-1) {}
Card::Card(int r, int s)
{
	const string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	suit = suits[s % 4]; // Map integer to suit
	setRank(r);
	value = (r > 10) ? 10 : r; // Face cards are worth 10
	if (r == 1)
		value = 11; // Ace is worth 11 by default
}

Card::Card(string s, int r, int v) 
{
	setSuit(s);
	setRank(r);
	setValue(v);
}


void Card::setSuit(const string& s) 
{
	suit = s;
}

// Sets the rank of the card, ensuring it's between 1 and 13
// 1 Ace , 2-10 numbered cards, 11 Jack, 12 Queen, 13 King
void Card::setRank(int r)
{
	if (r >=1 && r<=13)
		rank = r; 
	else
		cout << "Invalid rank: " << r << endl;
}


// Sets the value of the card, ensuring it's non-negative
void Card::setValue(int v)
{
	if (v>= 0)
	value = v;
	else
		cout << "Invalid value: " << v << endl;
}

int Card::getValue() const
{
	return value;
}

// Returns a string representation of the card
string Card::toString()const
{
	switch (rank)
	{
	case 1:
		return "A of " + suit;
	case 11:
		return "J of " + suit;
	case 12:
		return "Q of " + suit;
	case 13:
		return "K of " + suit;
	default: 
		if (rank > 1&& rank <=10)
			return to_string(rank) + " of " + suit;
		else
			return "Invalid Rank: " + to_string(rank);
	}
}

bool Card::isAce() const
{
	return rank ==1;
}


