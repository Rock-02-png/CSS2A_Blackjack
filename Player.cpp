#include "Player.h"
#include <string>


// Constructor initializes player attributes
Player::Player()
{
    setName("Unknown");
    setMoney(0);
    bet = 0;
}


// Sets the player's name
void Player::setName(string name) 
{
    this->name = name;
}


// Sets the player's money balance
void Player::setMoney(double money)
{
    this->money = money;
}


// Returns the player's name
string Player::getName()
{
	return name;
}


// Returns the player's current money balance
double Player::getMoney()
{
	return money;
}


// Adjusts the player's money based on winnings or losses
void Player::placeBet(double amount)
{
    if (amount > money) 
    {
        cout << "Not enough funds to place that bet!" << endl;
    }
    else {
        bet = amount;
        money -= amount;
        cout << name << " placed a bet of $" << bet << ". Remaining balance: $" << money << endl;
    }
}


// Places a bet if the player has enough funds
void Player::adjustMoney(double amount)
{
	money += amount;
	cout << name << "'s new balance: $" << money << endl;
}


// Player chooses to hit (draw a card from the deck)
void Player::hit(Deck& deck)
{
    if (deck.isEmpty() == false)
    {
        Card card = deck.drawCard();
        addCard(card);
        cout << name << " hit and drew: " << card.toString() << endl;
        cout << "New hand total: " << getTotalValue() << endl;
    }
    else {
        cout << "Deck is empty. No more cards to draw." << endl;

    }
}


// Player chooses to stand (stop drawing cards)
void Player::stand()
{
    cout << name << " stands with total value: " << getTotalValue() << endl;
}