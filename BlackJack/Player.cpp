#include "Player.h"

Player::Player(std::wstring name) : blackJack_(false), pass_(false), busts_(false), points_(0), name_(name) { }

void Player::TakeCard(Card* card)
{
	if (strcmp(card->GetRank(), "A ") == 0)
	{
		if (points_ > 11)
		{
			points_ += 1;
		}
		else if (cardsOnHand_.size() == 1 && (strcmp(cardsOnHand_[0]->GetRank(), "10") == 0) || strcmp(cardsOnHand_[0]->GetRank(), "A "))
		{
			points_ = 21;
			blackJack_ = true;
			pass_ = true;
		}
		else
		{
			points_ += card->GetPoints();
		}
	}
	else if (strcmp(card->GetRank(), "10") == 0)
	{
		if (cardsOnHand_.size() == 1 && strcmp(cardsOnHand_[0]->GetRank(), "A ") == 0)
		{
			points_ = 21;
			blackJack_ = true;
			pass_ = true;
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

	if (points_ == 21)
	{
		pass_ = true;
	}
	else if (points_ > 21)
	{
		pass_ = true;
		busts_ = true;
	}

	cardsOnHand_.push_back(card);
}

void Player::MakeAMove()
{

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

const std::vector<Card*>& Player::GetCardsOnHand() const
{
	return cardsOnHand_;
}