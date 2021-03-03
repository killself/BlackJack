#pragma once
#ifndef PlayerH
#define PlayerH

#include "io.h"
#include "fcntl.h"
#include <Windows.h>

#include "Deck.h"

class Player
{
public:

	Player(std::wstring name);
	void TakeCard(const Card& card);
	virtual void MakeAMove(Deck& deck);
	void ShowCards();

protected:

	int points_;
	std::vector<Card> cardsOnHand_;
	bool isBlackJack;
	std::wstring name_;
	bool isPass_;

	CONSOLE_SCREEN_BUFFER_INFO csbiInfo_;
	_COORD cursorPosition_;
	HANDLE hConsole_;
};

#endif