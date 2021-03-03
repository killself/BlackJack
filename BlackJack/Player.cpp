#include "Player.h"

Player::Player(std::wstring name) : isBlackJack(false), points_(0), isPass_(false), name_(name) 
{
	if (_setmode(_fileno(stdout), _O_U16TEXT) == -1)
	{
		throw;
	}

	hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Player::TakeCard(const Card& card)
{
	if (strcmp(card.GetRank(), "A ") == 0)
	{
		if (points_ > 11)
		{
			points_ += 1;
		}
		else if (cardsOnHand_.size() == 1 && strcmp(cardsOnHand_[0].GetRank(), "10") == 0)
		{
			points_ = 21;
			isBlackJack = true;
		}
		else
		{
			points_ += card.GetPoints();
		}
	}
	else if (strcmp(card.GetRank(), "10") == 0)
	{
		if (cardsOnHand_.size() == 1 && strcmp(cardsOnHand_[0].GetRank(), "A ") == 0)
		{
			points_ = 21;
			isBlackJack = true;
		}
		else
		{
			points_ += card.GetPoints();
		}
	}
	else
	{
		points_ += card.GetPoints();
	}

	cardsOnHand_.push_back(card);
}

void Player::MakeAMove(Deck& deck)
{

}

void Player::ShowCards()
{

	int changInX = 4;
	int changInY = -4;

	std::wcout << name_ <<"\nPoints: " << points_ << "\n";


	GetConsoleScreenBufferInfo(hConsole_, &csbiInfo_);
	cursorPosition_ = csbiInfo_.dwCursorPosition;


	for (Card card : cardsOnHand_)
	{
		SetConsoleCursorPosition(hConsole_, cursorPosition_);
		std::wcout << " -----";

		++cursorPosition_.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition_);
		std::wcout << "|" << card.GetRank() << "   |";

		++cursorPosition_.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition_);
		std::wcout << "|  " << card.GetSuitUnicode() << "  |";

		++cursorPosition_.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition_);
		std::wcout << "|     |";

		++cursorPosition_.Y;
		SetConsoleCursorPosition(hConsole_, cursorPosition_);
		std::wcout << " ----- ";

		cursorPosition_.X += changInX;
		cursorPosition_.Y += changInY;
	}

	std::wcout << "\n\n\n\n";
}