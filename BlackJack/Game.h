#pragma once
#ifndef GameH
#define GameH

#include <Windows.h>

#include "Dealer.h"
#include "HumanPlayer.h"
#include "Show.h"

class Game
{
public:

	Game();
	void Start();
	void Menu();

private:

	Deck deck_;
	std::vector<Player*> players;
	HumanPlayer player_;
	Dealer dealer_;
};

#endif