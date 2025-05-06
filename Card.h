//base class for the rest of the cards 


#pragma once
#include <string>
#include <iostream>


using namespace std;
class Card
{
private:
	string suit;
	string rank;
	int value;

public:
	Card();
	Card(string s, int r, int v);
	void setSuit(string s);
	void setRank(string r);
	void setValue(int v);

	string toString()const;

};

