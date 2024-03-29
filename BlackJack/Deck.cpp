#include "Deck.h"

Deck::Deck() : cardNum_(0)
{
	for (std::map<std::wstring, std::string>::iterator suitsIt = suits_.begin(); suitsIt != suits_.end(); ++suitsIt)
	{
		for (std::map<int, std::string>::iterator ranksIt = ranks_.begin(); ranksIt != ranks_.end(); ++ranksIt)
		{
			cards_.push_back(new Card(suitsIt->second.c_str(), suitsIt->first.c_str(), ranksIt->second.c_str(), ranksIt->first));
		}
	}

	shuffleTheDeck();
}

Card* Deck::GiveCard()
{
	if (cardNum_ == 52)
	{
		shuffleTheDeck();
		cardNum_ = 0;
	}

	return cards_[cardNum_++];
}

void Deck::shuffleTheDeck()
{
	unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine rnd(seed);
	std::shuffle(cards_.begin(), cards_.end(), rnd);
}