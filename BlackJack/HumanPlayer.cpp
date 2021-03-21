#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player(L"Player(you)") { }

void HumanPlayer::MakeAMove()
{
	if (cardsOnHand_.empty())
	{
		return;
	}
	else if (pass_ == true)
	{
		return;
	}

	char playerChoice = ' ';

	while (true)
	{
		std::wcout << "\nDo you want to take a card? (y/n): ";
		std::cin >> playerChoice;

		if (playerChoice == 'y')
		{			
			return;
		}
		else if (playerChoice == 'n')
		{
			pass_ = true;
			return;
		}
	}
}