#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Person.h"
#include "Game.h"

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
using namespace std;


/*  5/15/25 -Daniel Lara
	Updated main with Angelo's file. Now that we have a working round 1 we need a menu with start stop bets displayed , and a 
	loop to keep playing multiple rounds. maybe some exception handling too.	
*/

/*	5/17/25 -Daniel Lara
	Using Angelo's Main I created a Game class to encapsulate main game logic.
	Moved functionality from main into methods like play(), takeBet(), determineOutcome()
	for better organization & readability.	
	
	Also implemented overloaded operators for the Person Class to support comparisons & game logic. 
*/

int main()
{
	Game blackjack;
	blackjack.play();
	return 0;
}