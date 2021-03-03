#include "Card.h"

Card::Card(const char* suit, const wchar_t* suitUnicode, const char* rank, int points) : suit_(suit), suitUnicode_(suitUnicode), rank_(rank), points_(points)/*, inDeck_(true)*/ { }

//const bool Card::GetInDeck() const
//{
//	return inDeck_;
//}
//
//void Card::SetInDeck(bool inDeck)
//{
//	inDeck_ = inDeck;
//}

const char* Card::GetSuit() const
{
	return suit_;
}

const char* Card::GetRank() const
{
	return rank_;
}

const int Card::GetPoints() const
{
	return points_;
}

const wchar_t* Card::GetSuitUnicode() const
{
	return suitUnicode_;
}