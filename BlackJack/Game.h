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


private:

	bool EndRound();
	void ShowSituations(std::wstring name, std::wstring situation);
	void ShowCardsOnDesk();
	bool Menu();
	bool CheckSituations(const std::vector<Player*>& players) const;
	Deck deck_;
	Show show_;
	std::vector<Player*> players_;
	HumanPlayer player_;
	Dealer dealer_;
};

#endif