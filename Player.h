#pragma once
#include "Person.h"
#include "Deck.h"
#include <string>
using namespace std;

class Player : public Person
{
private:
	string name;
	double money, bet;
public:
	Player();
	//setters & getters 
	void setName(const string& name);
	void setMoney(double money);
	double getMoney()const;
	string getName()const;

	//betting & outcome handling
	bool placeBet(double amount);
	void win(double multiplier);
	void winBlackjack();
	void push();
	void lose();
	void adjustMoney(double amount);

	//gameplay
	void hit(Deck& deck);  // Draw a card
	void stand();          // Stop drawing cards
};