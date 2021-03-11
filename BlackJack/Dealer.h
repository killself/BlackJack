#pragma once
#ifndef DealerH
#define DealerH

#include "Player.h"

class Dealer : public Player
{
public:

	Dealer();
	void MakeAMove(Deck& deck) override;

private:
	

};

#endif