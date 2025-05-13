#include "Person.h"
#include <vector>
#include <string>


// Add card to the Persons hand
void Person::addCard(const Card& newCard)
{
    cards.push_back(newCard);
}

// Removes all hands cards
void Person::clear()
{
    cards.clear();
}

// Return the current cards in the Hand
const vector<Card>& Person::getCards() const
{
    return cards;
}

// Calculates the total value of the Person's hand, considering Aces as either 1 or 11
int Person::getTotalValue() const
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

// Checks if the Person's hand has Blackjack (Ace + 10-value card)
bool Person::hasBlackJack() const
{
    return (cards.size() == 2 && getTotalValue() == 21);
}

// Checks if the Person's hand is Bust (total value exceeds 21)
bool Person::isBust() const
{
    return (getTotalValue() > 21);
}

