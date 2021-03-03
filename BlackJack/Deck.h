#pragma once
#ifndef DeckH
#define DeckH

#include <map>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

#include "Card.h"

class Deck
{
public:

	Deck();	
	const Card& GiveCard();
	bool GetIsEmpty() const;

private:

	void shuffleTheDeck();
	std::multimap<int, std::string> ranks_{ {2, "2 "}, {3, "3 "}, {4, "4 "}, {5, "5 "}, {6, "6 "}, {7, "7 "}, {8, "8 "}, {9, "9 "}, {10, "10"}, {10, "J "}, {10, "Q "}, {10, "K "}, {11, "A "} };
	std::multimap<std::wstring, std::string> suits_ = { {L"\u2666", "Diamonds"}, {L"\u2665", "Hearts"}, {L"\u2663", "Clubs"}, {L"\u2660", "Spades"} };
	std::vector<Card> cards_;
	bool isEmpty_;
	unsigned int cardNum_;

};

#endif