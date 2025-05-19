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
void Player::setName(const string& name) 
{
    this->name = name;
}



void Player::win(double multiplier)
{
    money += bet * (1 + multiplier);
}
void Player::lose()
{
    cout << name << " lost the bet of $" << bet << ".\n";
}
void Player::push()
{
    money += bet;
}
void Player::winBlackjack()
{
    money += bet * 2.5;
    cout << name << " won with BlackJack! New Balance: $" << money << endl;
}



// Sets the player's money balance
void Player::setMoney(double money)
{
    this->money = money;
}


// Returns the player's name
string Player::getName()const
{
	return name;
}


// Returns the player's current money balance
double Player::getMoney() const
{
	return money;
}


// Adjusts the player's money based on winnings or losses
bool Player::placeBet(double amount)
{
    if (amount > money || amount <= 0) 
    {
        cout << "Invalid funds. You have $" << money << ".\n";
        return false;
    }
    else {
        bet = amount;
        money -= amount;
        cout << name << " placed a bet of $" << bet << ". Remaining balance: $" << money << endl;
        return true;
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
        cout << "New Person total: " << getTotalValue() << endl;
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