#include "Dealer.h"

Dealer::Dealer() : Player(L"Dealer") { }


void Dealer::MakeAMove(Deck& deck)
{
	if (cardsOnHand_.size() == 0)
	{
		TakeCard(deck.GiveCard());
		pass_ = true;
		return;
	}

	if (pass_)
	{
		return;
	}

	TakeCard(deck.GiveCard());

	if (points_ >= 17)
	{
		pass_ = true;
	}
}

