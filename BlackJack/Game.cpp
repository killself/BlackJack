#include "Game.h"

Game::Game() : deck_(Deck()), player_(HumanPlayer()), dealer_(Dealer()), show_(Show())
{	
	players_.push_back(&player_);
}

bool Game::Menu()
{
	char menu = '0';

	while (true)
	{
		std::wcout << "*********************************************************************************\n";
		Sleep(150);
		std::wcout << "\t\t\tThe Black Jack Game v0.01\n";
		Sleep(150);
		std::wcout << "*********************************************************************************\n\n";
		Sleep(150);
		std::wcout << "\nMENU:\n\n";
		Sleep(150);
		std::wcout << "1. Play the game\n";
		Sleep(150);
		std::wcout << "2. Exit\n";
		std::cin >> menu;

		if (menu == '1')
		{
			return false;
		}
		else if (menu == '2')
		{
			std::wcout << "\nGoodbye!\n\n";
			Sleep(900);
			return true;
		}

		system("cls");
	}
}

bool Game::EndRound()
{
	char playerChoice = ' ';

	while (true)
	{
		std::wcout << "Do you want play again?(y/n): ";
		std::cin >> playerChoice;

		if (playerChoice == 'y')
		{
			dealer_.NewPlay();

			for (Player* player : players_)
			{
				player->NewPlay();
			}

			return true;
		}
		else if (playerChoice == 'n')
		{
			break;
		}
	}

	return false;
}

void Game::CheckSituations()
{
	bool checkBusts = true;

	for (Player* player : players_)
	{
		checkBusts &= player->IsBusts();
	}

	if (!checkBusts)
	{
		while (!dealer_.IsPass())
		{
			dealer_.TakeCard(deck_.GiveCard());
			dealer_.MakeAMove();
			system("cls");
			ShowCardsOnDesk();
		}

		if (!dealer_.IsBusts())
		{
			for (Player* player : players_)
			{
				if (player->IsBusts())
				{
					ShowSituations(player->GetName(), L"lose");
				}
				else
				{
					if (player->GetPoints() > dealer_.GetPoints())
					{
						ShowSituations(player->GetName(), L"win");
						player->WinIncrease();

					}
					else if (player->GetPoints() < dealer_.GetPoints())
					{
						ShowSituations(player->GetName(), L"lose");
					}
					else if (player->GetPoints() == dealer_.GetPoints() && player->GetPoints() != 21)
					{
						ShowSituations(player->GetName(), L"Push");
					}
					else if (player->GetPoints() == dealer_.GetPoints() && player->GetPoints() == 21)
					{
						if (player->IsBlackJack() && !dealer_.IsBlackJack())
						{
							ShowSituations(player->GetName(), L"win");
							player->WinIncrease();
						}
						else if (!player->IsBlackJack() && dealer_.IsBlackJack())
						{
							ShowSituations(player->GetName(), L"lose");
						}
						else if (!player->IsBlackJack() && !dealer_.IsBlackJack())
						{
							ShowSituations(player->GetName(), L"Push");
						}
					}
				}
			}
		}
		else
		{
			for (Player* player : players_)
			{
				if (!player->IsBusts())
				{
					ShowSituations(player->GetName(), L"win");
					player->WinIncrease();
				}
			}
		}

		Sleep(1000);
	}
	else
	{
		if (!dealer_.IsBusts())
		{
			ShowSituations(dealer_.GetName(), L"win");
		}
		else
		{
			ShowSituations(L"All", L"lose =(");
		}

		Sleep(1000);
	}
}

void Game::ShowCardsOnDesk()
{
	show_.ShowCards(dealer_);

	for (Player* player : players_)
	{
		show_.ShowCards(*player);
	}
}

void Game::ShowSituations(std::wstring name, std::wstring situation)
{
	std::wcout << "------------------\n";
	std::wcout << name << ", "<< situation << "!";
	std::wcout << "\n------------------\n\n";
}

void Game::Start()
{
	if (Menu())
	{
		return;
	}

	dealer_.TakeCard(deck_.GiveCard());

	while (true)
	{	
		bool check = true;		

		for (Player* player : players_)
		{
			player->MakeAMove();

			if (!player->IsPass())
			{
				player->TakeCard(deck_.GiveCard());
				check = false;
			}
		}

		if (check)
		{
			CheckSituations();

			if (EndRound())
			{
				dealer_.TakeCard(deck_.GiveCard());
				continue;
			}
			else
			{
				std::wcout << "\nGoodbye!\n\n";
				Sleep(900);
				return;
			}
		}

		system("cls");
		ShowCardsOnDesk();
		Sleep(400);
	}
}