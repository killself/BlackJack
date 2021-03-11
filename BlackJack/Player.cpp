#include "Player.h"

Player::Player(std::wstring name) : isBlackJack(false), points_(0), pass_(false), name_(name) { }

void Player::TakeCard(Card* card)
{
	if (strcmp(card->GetRank(), "A ") == 0)
	{
		if (points_ > 11)
		{
			points_ += 1;
		}
		else if (cardsOnHand_.size() == 1 && strcmp(cardsOnHand_[0]->GetRank(), "10") == 0)
		{
			points_ = 21;
			isBlackJack = true;
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
			isBlackJack = true;
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

	if (points_ > 21)
	{
		pass_ = true;
	}

	cardsOnHand_.push_back(card);
}

void Player::MakeAMove(Deck& deck)
{

}

Situations Player::GetSituation() const
{
	return situation_;
}

bool Player::IsPass() 
{
	return pass_;
}

std::wstring Player::GetName() const
{
	return name_;
}

void Player::NotPass()
{
	pass_ = false;
}

int Player::GetPoints() const
{
	return points_;
}

const std::vector<Card*>& Player::GetCardsOnHand() const
{
	return cardsOnHand_;
}