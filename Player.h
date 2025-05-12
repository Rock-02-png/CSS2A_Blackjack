#pragma once
#include "Hand.h"
#include "Deck.h"
#include <string>
using namespace std;

class Player : public Hand
{
private:
	string name;
	double money, bet;
public:
	Player();
	void placeBet(double);
	void setName(string);
	void setMoney(double);
	string getName();
	double getMoney();
	void adjustMoney(double);
	void hit(Deck& deck);  // Draw a card
	void stand();          // Stop drawing cards
};