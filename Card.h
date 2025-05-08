//base class for the rest of the cards 


#pragma once
#include <string>
#include <iostream>


using namespace std;
class Card
{
private:
	string suit;
	int rank;
	int value;

public:
	Card();
	Card(string s, int r, int v);
	void setSuit(const string& s);
	void setRank(int r);
	void setValue(int v);
	int getValue() const;

	string toString()const;
};

