#pragma once
#ifndef GameH
#define GameH

#include "Dealer.h"
#include "HumanPlayer.h"

class Game
{
public:

	Game();
	void Start();

private:

	Deck deck_;
	std::vector<Player> players;
};

#endif