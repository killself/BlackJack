#pragma once
#ifndef ShowH
#define ShowH

#include "io.h"
#include "fcntl.h"
#include <Windows.h>
#include <vector>

#include "Player.h"

static class Show
{
public:
	Show();
	void ShowCards(const Player& player);

private:	
	HANDLE hConsole_;
};

#endif