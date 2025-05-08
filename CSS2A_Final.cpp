// css2a final blackjack sim 
// Daniel Lara

#include "Deck.h"
#include "Card.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
	Deck deck;

	while (deck.isEmpty() == false)
	{
		Card card = deck.drawCard();
		cout << card.toString() << endl;
	}
}