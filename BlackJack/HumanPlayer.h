#pragma once
#ifndef HumanPlayerH
#define HumanPlayerH

#include "Player.h"

class HumanPlayer : public Player
{
public:

	HumanPlayer();
	void MakeAMove(Deck& deck) override;

private:


};

#endif