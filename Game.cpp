#include "Game.h"

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Person.h"
using namespace std;

Game::Game()
{
	player.setName("Player 1");
	player.setMoney(1000);
	deck.shuffleDeck();
}
void Game::play()
{
	cout << "Welcome To Blackjack Simulator!! \n";
	while (player.getMoney() > 0)
	{
		roundCount++;  
		cout << "\n==== Round " << roundCount << " ====\n";

		takeBet();
		dealInitalCards();

		//card print
		printHand(player.getName(), player.getCards(), player.getTotalValue(), false);
		printHand("Dealer", dealer.getCards(), 0, true); // hide first card

		if (player.hasBlackJack())
		{
			cout << "!!BlackJack!! You win!\n";
			player.winBlackjack();
			continue;
		}

		if (dealer.hasBlackJack())
		{
			cout << "Dealer has Blackjack!! You lose!\n";

			continue;
		}

		playerTurn();
		if (!player.isBust())
		{
			dealerTurn();
		}

		determineOutcome();

		cout << "Money left: " << player.getMoney() << endl;
		
		string again;
		while (true)
		{
			cout << "Play Again?  (y/n): ";
			cin >> again;
			for (char& c : again) c = tolower(c);
			if (again == "y" || again == "n")
				break;
			cout << "Invalid input. Please enter 'y' or 'n'\n";
		}
		if (again == "n")
		{
			cout << "Thanks for playing! Goodbye.\n";
			break;
		}


		if (player.getMoney() <= 0) 
		{
			cout << "You're out of money.\n";
		}
	}
	cout << "Game over. Cash out: " << player.getMoney() << endl;
}

void Game::takeBet()
{
	while (true)
	{
		cout << "\nYou have $" << player.getMoney() << ". Place a bet: ";
		cin >> bet;
		if (cin.fail())
		{
			cin.clear(); // clear error 
			cin.ignore(1000, '\n'); // discard input
			cout << "Invalid input. Enter a number.\n";
		}
		else if (bet <= 0)
		{
			cout << "Bet must be greater than zero.\n";
		}
		else if (bet > player.getMoney())
		{
			cout << "Cant bet more than you have. \n";
		}
		else
		{
			break; // valid bet
		}
	}
	player.placeBet(bet);
}

void Game::dealInitalCards()
{
	checkDeck(); // to ensure deck has plety cards left
	player.clear();
	dealer.clear();
	// Initial deal
	cout << "Dealing cards...\n";
	player += deck.drawCard();
	player += deck.drawCard();
	dealer += deck.drawCard();
	dealer += deck.drawCard();
}
void Game::playerTurn()
{
	while (player.getTotalValue() < 21)
	{
		
		string response;
		// input validation for response
		while (true)
		{
			cout << "Hit or Stand? : ";
			cin >> response;
			for (char& c : response) c = tolower(c); 
			if (response == "hit" || response == "stand")
				break;
			cout << "Invalid input. Please enter 'hit' or 'stand'\n";
		}
		if (response == "hit")
		{
			checkDeck();
			player += deck.drawCard();
			printHand(player.getName(), player.getCards(), player.getTotalValue(), false);
			printHand("Dealer", dealer.getCards(), 0, true);
		}
		else if (response == "stand")
		{
			break;
		}
	}
}
void Game::dealerTurn()
{
	printHand(player.getName(), player.getCards(), player.getTotalValue(), false);
	printHand("Dealer", dealer.getCards(), dealer.getTotalValue(), false);
	while (dealer.getTotalValue() <= 17) //dealer hits untill 17 or more
	{
		checkDeck();
		dealer += deck.drawCard();
		printHand(player.getName(), player.getCards(), player.getTotalValue(), false);
		printHand("Dealer", dealer.getCards(), dealer.getTotalValue(), false);
	}
}

void Game::determineOutcome()
{
	if (player.isBust())
	{
		cout << "Busted! You Lost!\n";
		
	}
	else if (dealer.isBust() || player > dealer)
	{
		cout << "You win!\n";
		player.adjustMoney(bet*2);
	}
	else if (player == dealer)
	{
		cout << "Tie!\n";
		player.push(); //return bet
	}
	else
	{
		cout<< "You Lost!\n";
	}
}

//draws single card in a box 
void Game::pCardBox(const Card& card) const
{
	const int cardWidth = 14;
	string label = card.toString();

	if (label.length() > cardWidth)
		label = label.substr(0, cardWidth);
	else
		label += string(cardWidth - label.length(), ' ');

	cout << "+--------------+" << endl;
	cout << "|" << label << "|" << endl;

	// Add two empty lines for taller card
	for (int i = 0; i < 2; i++)
		cout << "|" << string(cardWidth, ' ') << "|" << endl;

	cout << "|" << string(cardWidth - 2, ' ') << label.substr(0, 2) << "|" << endl;
	cout << "+--------------+" << endl;
}

void Game::checkDeck()
{
	int cardsLeft = deck.cardsRemaining();
	int halfDeck = 52 / 2; 

	if (cardsLeft < halfDeck)
	{
		cout << "Deck is low, reshuffling...\n";
		deck.reset();
	}
}


//prints the entire hand for either player or dealer
void Game::printHand(const string& name, const vector<Card>& hand, int totalValue, bool hideFirst) const
{
	cout << "\n------------------------------\n";
	cout << name << "'s Hand:\n";

	if (hand.empty())
	{
		cout << "(No cards)\n";
		return;
	}

	// top border
	for (unsigned int i = 0; i < hand.size(); i++)
		cout << "+--------------+ ";
	cout << "\n";

	// rank/suit top-left or hidden
	for (unsigned int i = 0; i < hand.size(); i++)
	{
		string label;
		if (hideFirst && i == 0)
			label = "??";
		else
		{
			label = hand[i].toString();
			if (label.length() > 2)
				label = label.substr(0, 2);
		}

		cout << "|" << label << string(cardWidth - 2, ' ') << "| ";
	}
	cout << "\n";

	// empty middle line
	for (unsigned int i = 0; i < hand.size(); i++)
		cout << "|" << string(cardWidth, ' ') << "| ";
	cout << "\n";

	// rank/suit bottom
	for (unsigned int i = 0; i < hand.size(); i++)
	{
		string label;
		if (hideFirst && i == 0)
			label = "??";
		else
		{
			label = hand[i].toString();
			if (label.length() > 2)
				label = label.substr(0, 2);
		}

		cout << "|" << string(cardWidth - 2, ' ') << label << "| ";
	}
	cout << "\n";

	// bottom border
	for (unsigned int i = 0; i < hand.size(); i++)
		cout << "+--------------+ ";
	cout << "\n";

	// hands total display 
	if (!hideFirst)
		cout << name << "'s total: " << totalValue << "\n";
	else
	{
		int visibleTotal = 0;
		for (unsigned int i = 1; i < hand.size(); i++)
		{
			visibleTotal += hand[i].getValue();  // Make sure Card::getValue() returns card value
		}
		cout << name << "'s total: at least " << visibleTotal << "\n";
	}

	cout << "------------------------------\n\n";
}