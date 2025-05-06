#include "Card.h"
#include <iostream>
#include <string>


Card::Card() : suit("unknown"), rank(0), value(0) {}
Card::Card(string s, int r, int v):suit(s), rank(r), value(v) { }
void Card::setSuit(string s)
{
	suit = s;
}
void Card::setRank(string r)
{
	rank = r; 
}
void Card::setValue(int v)
{
	value = v; 
}

string Card::toString()const
{

}


