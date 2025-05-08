#include "Card.h"
#include <iostream>
#include <string>


Card::Card() : suit("unknown"), rank(-1), value(-1) {}
Card::Card(string s, int r, int v):suit(s), rank(r), value(v) 
{
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
		return "Ace of " + suit;
	case 11:
		return "Jack of " + suit;
	case 12:
		return "Queen of " + suit;
	case 13:
		return "King of " + suit;
	default: 
		if (rank > 1&& rank <=10)
			return to_string(rank) + " of " + suit;
		else
			return "Invalid Rank: " + to_string(rank);
	}
}


