#pragma once
#ifndef HumanPlayerH
#define HumanPlayerH

#include "Player.h"

class HumanPlayer : public Player
{
public:

	HumanPlayer();
	void MakeAMove() override;

private:


};

#endif