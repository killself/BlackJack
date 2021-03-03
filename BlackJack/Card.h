#pragma once
#ifndef CardH
#define CardH

#include <iostream>
#include <iomanip>

class Card
{
public:

	Card(const char* suit, const wchar_t* suitUnicode, const char* rank, int points);
	//const bool GetInDeck() const;
	//void SetInDeck(bool inDeck);
	const char* GetSuit() const;
	const char* GetRank() const;
	const wchar_t* GetSuitUnicode() const;
	const int GetPoints() const;	

private:

	const char* suit_;
	const char* rank_;
	const wchar_t* suitUnicode_;
	int points_;
	//bool inDeck_;
};

#endif