#include "Game.h"

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Person.h"

Game::Game()
{
	player.setName("Player 1");
	player.setMoney(1000);
	deck.shuffleDeck();
}
void Game::play()
{
	while (player.getMoney() > 0)
	{
		takeBet();
		dealInitalCards();
		showHands(false);

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
			player += deck.drawCard();
			showHands(false);
		}
		else if (response == "stand")
		{
			break;
		}
	}
}
void Game::dealerTurn()
{
	showHands(true);
	while (dealer.getTotalValue() <= 17)//dealer hits untill 17 or more
	{
		dealer += deck.drawCard();
		showHands(true);
	}
}
void Game::showHands(bool dealerHidden)
{
	// Display Hands
	cout << player.getName() << "'s Hand: \n";
	for (const auto& card : player.getCards()) {
		cout << card.toString() << endl;
	}
	cout << "Total value: " << player.getTotalValue() << endl;

	cout << "\nDealer's Hand: \n";
	if (dealerHidden)
	{
		for (const auto& card : dealer.getCards())
			cout << card.toString() << endl;
		cout << "Total Value: " << dealer.getTotalValue() << endl;
		
	}
	else
	{
		cout << dealer.getCards()[0].toString() << " face up\n";
		cout << "Hidden card (face down)\n";
	}
	// Check for blackjack
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
