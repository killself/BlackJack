#include "Dealer.h"

Dealer::Dealer() : Player(L"Dealer") { }


void Dealer::MakeAMove()
{
	if (points_ >= 17)
	{
		pass_ = true;
	}
}

