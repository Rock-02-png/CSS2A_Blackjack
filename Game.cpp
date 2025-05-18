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
			player.adjustMoney(bet);
			continue;
		}

		if (dealer.hasBlackJack())
		{
			cout << "Dealer has Blackjack!! You lose!\n";
			player.adjustMoney(-bet);
			continue;
		}

		playerTurn();
		if (!player.isBust())
		{
			dealerTurn();
		}

		determineOutcome();

		cout << "Money left: " << player.getMoney() << endl;
		cout << "Play again? (y/n): ";
		string again;
		cin >> again;
		if (again != "y" && again != "Y")
			break;

		if (player.getMoney() <= 0) 
		{
			cout << "You're out of money. Game over.\n";
		}
		cout << "Game over. Cash out: " << player.getMoney() << endl;
	}
}

void Game::takeBet()
{
	cout << "Place a bet: ";
	cin >> bet;
	while (bet > player.getMoney())
	{
		cout << "Place a bet: ";
		cin >> bet;
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
		cout << "Hit or Stand? : ";
		string response;
		cin >> response;
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
		player.adjustMoney(-bet);
	}
	else if (dealer.isBust() || player > dealer)
	{
		cout << "You win!\n";
		player.adjustMoney(bet);
	}
	else if (player == dealer)
	{
		cout << "Tie!\n";
	}
	else
	{
		cout<< "You Lost!\n";
		player.adjustMoney(-bet);
	}
}
