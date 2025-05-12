// css2a final blackjack sim 
// Daniel Lara

#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Dealer.h"
#include "Player.h"



#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>

using namespace std;

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

    deck.shuffleDeck();
    p1.setName("Player 1");
    p1.setMoney(1000);

    // Initial deal
    cout << "Dealing cards...\n";

    p1.addCard(deck.drawCard());
    p1.addCard(deck.drawCard());

    dealer.addCard(deck.drawCard());
    dealer.addCard(deck.drawCard());

    // Display hands
    cout << p1.getName() << "'s hand: \n";
    for (const auto& card : p1.getCards()) {
        cout << card.toString() << endl;
    }
    cout << "Total value: " << p1.getTotalValue() << endl;  // Correctly calling on p1

    cout << "Dealer's hand: \n";
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
    cout << "Hit or Stand? : ";
    return 0;

}