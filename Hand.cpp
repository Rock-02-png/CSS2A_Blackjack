#include "Hand.h"
#include <vector>
#include <string>


// Add card to the hand
void Hand::addCard(Card newCard)
{
	cards.push_back(newCard);
}


 // Removes all hand
void Hand::clear() 
{
	cards.clear();
}


// return the current cards in the hand
vector <Card> Hand::getCards()
{
	return cards;
}


// Calculates the total value of the hand, considering Aces as either 1 or 11
int Hand::getTotalValue()
{
	int totalValue = 0;
    bool hasAce = false;
    for (const Card& card : cards) {
        if (card.toString().substr(0, 3) == "Ace") 
        {
            hasAce = true;
            break;
        }
    }

    // If the hand contains an Ace and total value is <= 11, count the Ace as 11
    if (hasAce && totalValue <= 11)
    {
        totalValue += 10;
    }

    return totalValue;
}


// Checks if the hand has Blackjack (Ace + 10-value card)
bool Hand::hasBlackJack()
{
	return (cards.size() == 2 && getTotalValue() == 21);
}


// Checks if the hand is Bust(total value exceeds 21)
bool Hand::isBust()
{
	return (getTotalValue() > 21);
}