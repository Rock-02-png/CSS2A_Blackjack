#include "Deck.h"
#include "Card.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>



Deck::Deck()
{
	reset();
}

void Deck::reset()
{
	cards.clear();
	string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	for (const auto& suit : suits)
	{
		for (int rank = 1; rank <= 13; ++rank)
		{
			int value = (rank > 10) ? 10 : rank; // Face cards are worth 10
			cards.emplace_back(suit, rank, value);
		}
	}
	currentCard = 0; // Reset the current card index
	shuffleDeck(); // Shuffle the deck after resetting
}

// Shuffles the deck using a random number generator, makes use of algorithm and random libraries
void Deck::shuffleDeck()
{
	random_device rd;
	mt19937 g(rd());
	shuffle(cards.begin(), cards.end(), g);
	currentCard = 0; // Reset the current card index after shuffling
}


Card Deck::drawCard()
{
	if (currentCard >= cards.size())
	{
		cout << "No more cards to draw." << endl;
		return Card();
	}
	return cards[currentCard++];
	 
}


bool Deck::isEmpty() const
{
	return currentCard >= cards.size();
}
int Deck::cardsRemaining() const
{
	return cards.size()- currentCard;
}

int Deck::totalCards() const
{
	return cards.size();
}

