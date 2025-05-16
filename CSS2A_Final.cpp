#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
using namespace std;

/* one more class named something like "Game Start" would be nice to clean up the main
it would have all the things that happen, menus,hit and stand options as well as displays like
"Win!" or "Lose"
maybe something to make use of the bet method as well.
hit is already written as the draw method in deck. Stand is just do not draw, so keep current
value.
bet and money methods are in player
NOTE!! look out for issues with the Hand to person name change since i did it all at once
after this the project should be mostly done and if we have time we can add graphics.
*/


/*  5/15/25
	updated main with Angelo's file. Now that we have a working round 1 we need a menu with start stop bets displayed , and a 
	loop to keep playing multiple rounds. maybe some exception handling too 
*/


int main()
{
	/* test loop to print deck
	while (deck.isEmpty() == false)
	{
	Card card = deck.drawCard();
	cout << card.toString() << endl;
	}*/


	Deck deck;
	Player p1;
	Dealer dealer;
	double bet;
	deck.shuffleDeck();
	p1.setName("Player 1");
	p1.setMoney(1000);
	cout << "Place a bet: ";
	cin >> bet;
	while (bet > p1.getMoney())
	{
		p1.placeBet(bet);
		cout << "Place a bet: ";
		cin >> bet;
	}
	p1.placeBet(bet);
	// Initial deal
	cout << "Dealing cards...\n";
	p1.addCard(deck.drawCard());
	p1.addCard(deck.drawCard());
	dealer.addCard(deck.drawCard());
	dealer.addCard(deck.drawCard());
	// Display Persons
	cout << p1.getName() << "'s Hand: \n";
	for (const auto& card : p1.getCards()) {
		cout << card.toString() << endl;
	}
	cout << "Total value: " << p1.getTotalValue() << endl;
	cout << "Dealer's Hand: \n";
	cout << dealer.getCards()[0].toString() << " face up\n";
	cout << "Hidden card(face down)\n";
	// Check for blackjack
	if (p1.hasBlackJack()) {
		cout << p1.getName() << " has Blackjack! \n";
		return 0;
	}
	if (dealer.hasBlackJack()) {
		cout << "Dealer has Blackjack! \n";
		return 0;
	}
	// Game continues
	while (p1.getTotalValue() < 21)
	{
		cout << "Hit or Stand? : ";
		string response;
		cin >> response;
		if (response == "hit")
		{
			p1.addCard(deck.drawCard());
			cout << p1.getName() << "'s Hand: \n";
			for (const auto& card : p1.getCards()) {
				cout << card.toString() << endl;
			}
			cout << "Total value: " << p1.getTotalValue() << endl;
		}
		else if (response == "stand")
		{
			break;
		}
	}
	if (p1.getTotalValue() > 21)
	{
		cout << "Busted! You lost! " << endl;
		p1.adjustMoney(-bet);
	}
	else if (p1.getTotalValue() == 21)
	{
		cout << "You win! " << endl;
		p1.adjustMoney(bet);
	}
	else
	{
		cout << "Dealer's Hand: \n";
		cout << dealer.getCards()[0].toString() << " face up\n";
		cout << dealer.getCards()[1].toString() << " face up\n";
		while (dealer.getTotalValue() < 21 && p1.getTotalValue() > dealer.getTotalValue())
		{
			dealer.addCard(deck.drawCard());
		}
		if (dealer.getTotalValue() <= 21 && p1.getTotalValue() < dealer.getTotalValue())
		{
			cout << "You lost! Dealer has " << dealer.getTotalValue() << " while you had " <<
				p1.getTotalValue() << endl;
			p1.adjustMoney(-bet);
		}
		else if (dealer.getTotalValue() <= 21 && p1.getTotalValue() == dealer.getTotalValue())
		{
			cout << "Tie! Dealer and Player got the same score of " << p1.getTotalValue() << endl;
			p1.adjustMoney(0);
		}
		else
		{
			cout << "You win! The dealer busted with " << dealer.getTotalValue() << endl;
			p1.adjustMoney(+bet);
		}
	}
	return 0;
}