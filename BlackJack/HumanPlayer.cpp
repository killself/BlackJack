#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player(L"Player(you)") { }

void HumanPlayer::MakeAMove(Deck& deck)
{
	if (isPass_)
	{
		return;
	}

	char playerChoice = ' ';

	while (true)
	{
		std::wcout << "Do you want to take a card? (y/n)";
		std::cin >> playerChoice;

		if (playerChoice == 'y')
		{
			TakeCard(deck.GiveCard());
			return;
		}
		else if (playerChoice == 'n')
		{
			isPass_ = true;
			return;
		}
	}
}