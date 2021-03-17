#pragma once
#ifndef DealerH
#define DealerH

#include "Player.h"

class Dealer : public Player
{
public:

	Dealer();
	void MakeAMove() override;

private:
	

};

#endif