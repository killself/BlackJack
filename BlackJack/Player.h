#pragma once
#ifndef PlayerH
#define PlayerH

#include "Deck.h"

//enum class Situations
//{
//	Pass,
//	TwentyOne,
//	BlackJack,
//	Busts,
//};

class Player
{
public:

	Player(std::wstring name);
	void TakeCard(Card* card);
	virtual void MakeAMove();
	//Situations GetSituation() const;
	bool IsPass();
	std::wstring GetName() const;
	int GetPoints() const;
	const std::vector<Card*>& GetCardsOnHand() const;

protected:

	//Situations situation_;
	int points_;
	std::vector<Card*> cardsOnHand_;
	bool isBlackJack;
	std::wstring name_;
	bool pass_;
};

#endif