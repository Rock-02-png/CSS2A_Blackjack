#include "Hand.h"
#include <vector>
#include <string>


// Add card to the hand
void Hand::addCard(const Card& newCard)
{
    cards.push_back(newCard);
}

// Removes all hand
void Hand::clear()
{
    cards.clear();
}

// Return the current cards in the hand
const vector<Card>& Hand::getCards() const
{
    return cards;
}

// Calculates the total value of the hand, considering Aces as either 1 or 11
int Hand::getTotalValue() const
{
    int totalValue = 0;
    int aceCount = 0;
    for (const Card& card : cards)
    {
        totalValue += card.getValue();
        if (card.isAce())
            aceCount++;
    }

    while (aceCount > 0 && totalValue <= 11)
    {
        totalValue += 10;
        aceCount--;
    }

    return totalValue;
}

// Checks if the hand has Blackjack (Ace + 10-value card)
bool Hand::hasBlackJack() const
{
    return (cards.size() == 2 && getTotalValue() == 21);
}

// Checks if the hand is Bust (total value exceeds 21)
bool Hand::isBust() const
{
    return (getTotalValue() > 21);
}

