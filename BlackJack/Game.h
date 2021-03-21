#pragma once
#ifndef GameH
#define GameH

#include <Windows.h>

#include "Dealer.h"
#include "HumanPlayer.h"
#include "Show.h"

class Game
{
public:

	Game();
	void Start();


private:

	bool EndRound(); // запрос на повторный раунд и обнуление статов у игроков
	void ShowSituations(std::wstring name, std::wstring situation); // выводит выиграл или проиграл конкретный игрок
	void ShowCardsOnDesk(); // отображение карт
	bool Menu();
	void CheckSituations(); // Проверка исхода игры
	Deck deck_;
	Show show_;
	std::vector<Player*> players_;
	HumanPlayer player_;
	Dealer dealer_;
};

#endif