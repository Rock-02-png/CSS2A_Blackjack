
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

// Overloaded Operators
Person& Person::operator+= (const Card& card)
{
    addCard(card);
    return *this;
}
bool operator>(const Person& a, const Person& b)
{
    // blackjack checks
    if (a.hasBlackJack() && !b.hasBlackJack()) return true; // if a has blackjack but b doesnt, a wins
    if (b.hasBlackJack() && !a.hasBlackJack()) return false; // if b has blackjack but a doesnt, b wins
    if (a.isBust()) return false; // a is bust, cant beat b
    if (b.isBust()) return true; // b is bust, cant beat a
    return a.getTotalValue() > b.getTotalValue(); // neither bust, compare totals
}
// same as > but opposite
bool operator<(const Person& a, const Person& b)
{
    // blackjack checks
    if (a.hasBlackJack() && !b.hasBlackJack()) return false; 
    if (b.hasBlackJack() && !a.hasBlackJack()) return true; 
    if (a.isBust()) return true; 
    if (b.isBust()) return false; 
    return a.getTotalValue() < b.getTotalValue(); 
}
bool operator==(const Person& a, const Person& b)
{
    if (a.isBust() && b.isBust()) return true; // both players bust
    if (a.hasBlackJack() && b.hasBlackJack()) return true; // both have blackjack
    if (!a.isBust() && !b.isBust() && !a.hasBlackJack() && !b.hasBlackJack()) // neither bust or blackjack and their totals match
        return a.getTotalValue() == b.getTotalValue();
    return false; // otherwise false
}
bool operator!=(const Person& a, const Person& b)
{
    return !(a == b);
}
bool operator<=(const Person& a, const Person& b)
{
    return (a < b) || (a == b);
}
bool operator>=(const Person& a, const Person& b)
{
    return (a > b) || (a == b);
}
