#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player(L"Player(you)") { }

void HumanPlayer::MakeAMove(Deck& deck)
{
	if (pass_)
	{
		return;
	}
	
	if (cardsOnHand_.size() == 0)
	{
		TakeCard(deck.GiveCard());
		return;
	}

	char playerChoice = ' ';

	while (true)
	{
		std::wcout << "\nDo you want to take a card? (y/n): ";
		std::cin >> playerChoice;

		if (playerChoice == 'y')
		{
			TakeCard(deck.GiveCard());
			return;
		}
		else if (playerChoice == 'n')
		{
			pass_ = true;
			return;
		}
	}
}