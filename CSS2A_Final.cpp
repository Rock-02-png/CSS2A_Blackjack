// css2a final blackjack sim test main 


#include "Deck.h"
#include "Card.h"
#include "Person.h"
#include "Dealer.h"
#include "Player.h"



#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>

using namespace std;

/* one more class named something like "Game Start" would be nice to clean up the main
   it would have all the things that happen, menus,hit and stand options as well as displays like "Win!" or "Lose" 
   maybe something to make use of the bet method as well.

   hit is already written as the draw method in deck. Stand is just do not draw, so keep current value. 
   bet and money methods are in player 

   NOTE!! look out for issues with the Hand to person name change since i did it all at once

   after this the project should be mostly done and if we have time we can add graphics. 
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

    deck.shuffleDeck();
    p1.setName("Player 1");
    p1.setMoney(1000);

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
    cout << "Hit or Stand? : ";
    return 0;

}