#include "Person.h"
#include "Dealer.h"
#include <string>
#include <iostream>
using namespace std;

Dealer::Dealer()
{

}


// Determines whether dealer should hit or stand based on Blackjack rules
bool Dealer::shouldHit()
{
	return getTotalValue() <= 16; // Dealer hits if total is 16 or less

}


// Dealer automatically plays its turn following standard Blackjack rules
void Dealer::playTurn(Deck& deck)
{
    cout << "Dealer's turn begins..." << endl;

    // Dealer continues hitting until Person value is 17 or more
    while (shouldHit() && deck.isEmpty()== false) 
    { 
        Card card = deck.drawCard();
        addCard(card);
        cout << "Dealer drew: " << card.toString() << endl;
        cout << "Dealer's new Person total: " << getTotalValue() << endl;
    }

    cout << "Dealer stands with total value: " << getTotalValue() << endl;
}