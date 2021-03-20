#pragma once
#ifndef PlayerH
#define PlayerH

#include "Deck.h"

class Player
{
public:

	Player(std::wstring name);
	void TakeCard(Card* card);
	virtual void MakeAMove();
	bool IsPass() const;
	bool IsBusts() const;
	bool IsBlackJack() const;
	std::wstring GetName() const;
	int GetPoints() const;
	const std::vector<Card*>& GetCardsOnHand() const;
	void NewPlay();

protected:

	int points_;
	std::vector<Card*> cardsOnHand_;
	std::wstring name_;
	bool pass_;
	bool busts_;
	bool blackJack_;
};

#endif