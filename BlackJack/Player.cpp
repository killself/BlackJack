#include "Player.h"

Player::Player(std::wstring name) : blackJack_(false), pass_(false), busts_(false), points_(0), winsCount_(0), name_(name) { }

void Player::TakeCard(Card* card)
{
	if (strcmp(card->GetRank(), "A ") == 0)  // Если сумма очков больше 11 то туз добавляет 1 очко
	{
		if (points_ > 11)
		{
			points_ += 1;
		}
		else
		{
			points_ += card->GetPoints();
		}
	}
	else
	{
		points_ += card->GetPoints();
	}

	cardsOnHand_.push_back(card);

	if (points_ == 21)
	{
		pass_ = true;
	}
	else if (points_ > 21)
	{
		pass_ = true;
		busts_ = true;
	}

	if (cardsOnHand_.size() == 2 && ((strcmp(cardsOnHand_[0]->GetRank(), "10") == 0) && (strcmp(cardsOnHand_[1]->GetRank(), "A ") == 0)  // Проверка на комбинацию "Туз" и "10"
		                         || ((strcmp(cardsOnHand_[1]->GetRank(), "10") == 0) && (strcmp(cardsOnHand_[0]->GetRank(), "A ") == 0))))
	{
		blackJack_ = true;
		pass_ = true;
		points_ = 21;
	}
}

void Player::MakeAMove()
{

}

void Player::WinIncrease()
{
	++winsCount_;
}


void Player::NewPlay()
{
	cardsOnHand_.clear();
	pass_ = false;
	points_ = 0;
	blackJack_ = false;
	busts_ = false;
}

bool Player::IsPass() const
{
	return pass_;
}

bool Player::IsBusts() const
{
	return busts_;
}

bool Player::IsBlackJack() const
{
	return blackJack_;
}

std::wstring Player::GetName() const
{
	return name_;
}

int Player::GetPoints() const
{
	return points_;
}

int Player::GetWinsCount() const
{
	return winsCount_;
}


const std::vector<Card*>& Player::GetCardsOnHand() const
{
	return cardsOnHand_;
}