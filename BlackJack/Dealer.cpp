#include "Dealer.h"

Dealer::Dealer() : Player(L"Dealer") { }


void Dealer::MakeAMove(Deck& deck)
{
	if (isPass_)
	{
		return;
	}

	TakeCard(deck.GiveCard());

	if (points_ > 19)
	{
		isPass_ = true;
	}
}